#include "DesktopUtils.hpp"
#include <QFileInfo>
#include <QHash>
#include <QStringList>

QString DesktopUtils::getIconName(const QString &fileName, bool isDir) const {
    if (isDir) return "folder";
    QString ext = QFileInfo(fileName).suffix().toLower();

    static const QHash<QString, QString> map = {
        // Images
        {"png", "image-x-generic"}, {"jpg", "image-x-generic"}, {"jpeg", "image-x-generic"}, {"svg", "image-svg+xml"},
        {"gif", "image-x-generic"}, {"bmp", "image-x-generic"}, {"webp", "image-x-generic"}, {"ico", "image-x-generic"},
        {"tiff", "image-x-generic"}, {"tif", "image-x-generic"}, {"heic", "image-x-generic"}, {"heif", "image-x-generic"},
        {"raw", "image-x-generic"}, {"psd", "image-vnd.adobe.photoshop"}, {"ai", "application-illustrator"}, {"xcf", "image-x-xcf"},

        // Videos
        {"mp4", "video-x-generic"}, {"mkv", "video-x-generic"}, {"webm", "video-x-generic"}, {"avi", "video-x-generic"},
        {"mov", "video-x-generic"}, {"flv", "video-x-generic"}, {"wmv", "video-x-generic"}, {"m4v", "video-x-generic"},
        {"mpg", "video-x-generic"}, {"mpeg", "video-x-generic"}, {"3gp", "video-x-generic"}, {"vob", "video-x-generic"},
        {"ogv", "video-x-generic"}, {"ts", "video-x-generic"},

        // Audio
        {"mp3", "audio-x-generic"}, {"wav", "audio-x-generic"}, {"flac", "audio-x-generic"}, {"aac", "audio-x-generic"},
        {"ogg", "audio-x-generic"}, {"m4a", "audio-x-generic"}, {"wma", "audio-x-generic"}, {"opus", "audio-x-generic"},
        {"alac", "audio-x-generic"}, {"mid", "audio-midi"}, {"midi", "audio-midi"}, {"amr", "audio-x-generic"},

        // Archives & Images
        {"zip", "application-zip"}, {"tar", "application-x-tar"}, {"gz", "application-gzip"}, {"rar", "application-vnd.rar"},
        {"7z", "application-x-7z-compressed"}, {"xz", "application-x-xz"}, {"bz2", "application-x-bzip2"}, {"tgz", "application-x-compressed-tar"},
        {"iso", "application-x-cd-image"}, {"img", "application-x-cd-image"}, {"dmg", "application-x-apple-diskimage"},
        {"deb", "application-vnd.debian.binary-package"}, {"rpm", "application-x-rpm"}, {"apk", "application-vnd.android.package-archive"},

        // Documents
        {"pdf", "application-pdf"}, {"doc", "application-msword"}, {"docx", "application-vnd.openxmlformats-officedocument.wordprocessingml.document"},
        {"xls", "application-vnd.ms-excel"}, {"xlsx", "application-vnd.openxmlformats-officedocument.spreadsheetml.sheet"},
        {"ppt", "application-vnd.ms-powerpoint"}, {"pptx", "application-vnd.openxmlformats-officedocument.presentationml.presentation"},
        {"odt", "application-vnd.oasis.opendocument.text"}, {"ods", "application-vnd.oasis.opendocument.spreadsheet"},
        {"odp", "application-vnd.oasis.opendocument.presentation"}, {"rtf", "application-rtf"}, {"epub", "application-epub+zip"},
        {"mobi", "application-x-mobipocket-ebook"}, {"djvu", "image-vnd.djvu"}, {"csv", "text-csv"}, {"tsv", "text-tab-separated-values"},

        // Data & Config
        {"txt", "text-x-generic"}, {"md", "text-markdown"}, {"rst", "text-x-rst"}, {"tex", "text-x-tex"}, {"log", "text-x-log"},
        {"json", "application-json"}, {"xml", "text-xml"}, {"yaml", "text-x-yaml"}, {"yml", "text-x-yaml"}, {"toml", "text-x-toml"},
        {"ini", "text-x-generic"}, {"conf", "text-x-generic"}, {"cfg", "text-x-generic"}, {"env", "text-x-generic"},

        // Code
        {"qml", "text-x-qml"}, {"cpp", "text-x-c++src"}, {"c", "text-x-csrc"}, {"h", "text-x-chdr"}, {"hpp", "text-x-c++hdr"},
        {"py", "text-x-python"}, {"js", "text-x-javascript"}, {"ts", "text-x-typescript"}, {"jsx", "text-x-javascript"}, {"tsx", "text-x-typescript"},
        {"java", "text-x-java"}, {"rs", "text-x-rust"}, {"go", "text-x-go"}, {"rb", "text-x-ruby"}, {"php", "application-x-php"},
        {"cs", "text-x-csharp"}, {"swift", "text-x-swift"}, {"kt", "text-x-kotlin"}, {"sh", "application-x-shellscript"},
        {"bash", "application-x-shellscript"}, {"zsh", "application-x-shellscript"}, {"fish", "application-x-shellscript"},
        {"html", "text-html"}, {"htm", "text-html"}, {"css", "text-css"}, {"scss", "text-x-scss"}, {"sass", "text-x-sass"}, {"less", "text-x-less"},
        {"vue", "text-html"}, {"svelte", "text-html"}, {"sql", "application-x-sql"}, {"graphql", "text-x-generic"}, {"lua", "text-x-lua"},
        {"pl", "text-x-perl"}, {"dart", "text-x-dart"}, {"r", "text-x-r"}, {"dockerfile", "text-x-generic"}, {"make", "text-x-makefile"},

        // Executables
        {"exe", "application-x-executable"}, {"msi", "application-x-msi"}, {"bat", "application-x-ms-dos-executable"},
        {"cmd", "application-x-ms-dos-executable"}, {"appimage", "application-x-executable"}, {"run", "application-x-executable"},
        {"bin", "application-x-executable"}, {"out", "application-x-executable"}, {"so", "application-x-sharedlib"},
        {"dll", "application-x-sharedlib"},

        // Fonts
        {"ttf", "font-x-generic"}, {"otf", "font-x-generic"}, {"woff", "font-x-generic"}, {"woff2", "font-x-generic"}
    };
    return map.value(ext, "text-x-generic");
}

QString DesktopUtils::getFileType(const QString &fileName, bool isDir) const {
    if (isDir) return "directory";

    QString ext = QFileInfo(fileName).suffix().toLower();
    if (ext.isEmpty()) return "unknown";
    if (ext == "desktop") return "desktop";

    static const QHash<QString, QString> typeMap = {
        {"png", "image"}, {"jpg", "image"}, {"jpeg", "image"}, {"svg", "image"}, {"gif", "image"},
        {"bmp", "image"}, {"webp", "image"}, {"ico", "image"}, {"tiff", "image"}, {"tif", "image"},
        {"heic", "image"}, {"heif", "image"}, {"raw", "image"}, {"psd", "image"}, {"ai", "image"},
        {"xcf", "image"},

        {"mp4", "video"}, {"mkv", "video"}, {"webm", "video"}, {"avi", "video"}, {"mov", "video"},
        {"flv", "video"}, {"wmv", "video"}, {"m4v", "video"}, {"mpg", "video"}, {"mpeg", "video"},
        {"3gp", "video"}, {"vob", "video"}, {"ogv", "video"}, {"ts", "video"},

        {"mp3", "audio"}, {"wav", "audio"}, {"flac", "audio"}, {"aac", "audio"}, {"ogg", "audio"},
        {"m4a", "audio"}, {"wma", "audio"}, {"opus", "audio"}, {"alac", "audio"}, {"mid", "audio"},
        {"midi", "audio"}, {"amr", "audio"},

        {"zip", "archive"}, {"tar", "archive"}, {"gz", "archive"}, {"rar", "archive"}, {"7z", "archive"},
        {"xz", "archive"}, {"bz2", "archive"}, {"tgz", "archive"}, {"iso", "archive"}, {"img", "archive"},
        {"dmg", "archive"}, {"deb", "archive"}, {"rpm", "archive"}, {"apk", "archive"},

        {"pdf", "document"}, {"doc", "document"}, {"docx", "document"}, {"xls", "document"},
        {"xlsx", "document"}, {"ppt", "document"}, {"pptx", "document"}, {"odt", "document"},
        {"ods", "document"}, {"odp", "document"}, {"rtf", "document"}, {"epub", "document"},
        {"mobi", "document"}, {"djvu", "document"},

        {"txt", "text"}, {"md", "text"}, {"rst", "text"}, {"tex", "text"}, {"log", "text"},
        {"json", "text"}, {"xml", "text"}, {"yaml", "text"}, {"yml", "text"}, {"toml", "text"},
        {"ini", "text"}, {"conf", "text"}, {"cfg", "text"}, {"env", "text"}, {"csv", "text"},
        {"tsv", "text"},

        {"qml", "code"}, {"cpp", "code"}, {"c", "code"}, {"h", "code"}, {"hpp", "code"}, {"py", "code"},
        {"js", "code"}, {"ts", "code"}, {"jsx", "code"}, {"tsx", "code"}, {"java", "code"}, {"rs", "code"},
        {"go", "code"}, {"rb", "code"}, {"php", "code"}, {"cs", "code"}, {"swift", "code"}, {"kt", "code"},
        {"sh", "code"}, {"bash", "code"}, {"zsh", "code"}, {"fish", "code"}, {"html", "code"}, {"htm", "code"},
        {"css", "code"}, {"scss", "code"}, {"sass", "code"}, {"less", "code"}, {"vue", "code"}, {"svelte", "code"},
        {"sql", "code"}, {"graphql", "code"}, {"lua", "code"}, {"pl", "code"}, {"dart", "code"}, {"r", "code"},
        {"dockerfile", "code"}, {"make", "code"},

        {"exe", "executable"}, {"msi", "executable"}, {"bat", "executable"}, {"cmd", "executable"},
        {"appimage", "executable"}, {"run", "executable"}, {"bin", "executable"}, {"out", "executable"},
        {"so", "executable"}, {"dll", "executable"},

        {"ttf", "font"}, {"otf", "font"}, {"woff", "font"}, {"woff2", "font"}
    };

    return typeMap.value(ext, "unknown");
}

QString DesktopUtils::getAppId(const QString &fileName) const {
    if (fileName.endsWith(".desktop")) {
        QString res = fileName;
        return res.remove(".desktop");
    }
    return QString();
}