
#include "ObjectUtils.hpp"
#include <QJSValueIterator>

QJSValue ObjectUtils::toPlainObject(QJSValue qtObj) const {
    if (!qtObj.isObject() || qtObj.isNull()) return qtObj;
    
    QJSEngine *engine = qjsEngine(this);
    if (!engine) return QJSValue();

    if (qtObj.isArray()) {
        QJSValue arr = engine->newArray(qtObj.property("length").toInt());
        int length = qtObj.property("length").toInt();
        for (int i = 0; i < length; ++i) {
            arr.setProperty(i, toPlainObject(qtObj.property(i)));
        }
        return arr;
    }

    QJSValue result = engine->newObject();
    QJSValueIterator it(qtObj);
    while (it.hasNext()) {
        it.next();
        QString key = it.name();
        if (!key.startsWith("objectName") && !key.startsWith("children") &&
            !key.startsWith("object") && !key.startsWith("parent") &&
            !key.startsWith("metaObject") && !key.startsWith("destroyed") &&
            !key.startsWith("reloadableId") && !it.value().isCallable()) {
            result.setProperty(key, toPlainObject(it.value()));
        }
    }
    return result;
}

void ObjectUtils::applyToQtObject(QJSValue qtObj, QJSValue jsonObj) const {
    if (!qtObj.isObject() || !jsonObj.isObject() || jsonObj.isNull()) return;

    if (qtObj.isArray() && jsonObj.isArray()) {
        qtObj.setProperty("length", 0);
        int len = jsonObj.property("length").toInt();
        for (int i = 0; i < len; ++i) {
            qtObj.setProperty(i, jsonObj.property(i));
        }
        return;
    }

    QJSValueIterator it(jsonObj);
    while (it.hasNext()) {
        it.next();
        QString key = it.name();
        if (!qtObj.hasProperty(key)) continue;

        QJSValue targetVal = qtObj.property(key);
        QJSValue sourceVal = it.value();

        if (targetVal.isArray() && sourceVal.isArray()) {
            targetVal.setProperty("length", 0);
            int len = sourceVal.property("length").toInt();
            for (int i = 0; i < len; ++i) {
                targetVal.setProperty(i, sourceVal.property(i));
            }
        } else if (targetVal.isObject() && !targetVal.isArray() && sourceVal.isObject() && !sourceVal.isArray()) {
            applyToQtObject(targetVal, sourceVal);
        } else {
            qtObj.setProperty(key, sourceVal);
        }
    }
}
