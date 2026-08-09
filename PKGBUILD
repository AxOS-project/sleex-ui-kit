pkgname="sleex-ui-kit"
pkgver="1.0"
pkgrel="5"
pkgdesc="UI kit with a collection of Qt components with Sleex design language"
arch=("x86_64")
depends=(
  "qt6-base" "qt6-declarative" "qt6-tools" "qt6-wayland"
)
makedepends=("cmake")
optdepends=(
  "sleex: Sleex desktop environment"
)

build() {
  rm -rf build/
  cmake -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
  cmake --build build -j$(nproc --ignore=2)
}

package() {
  cd build
  DESTDIR="$pkgdir" cmake --install .
}
