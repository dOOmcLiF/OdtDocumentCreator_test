/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 6.7.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/qt_programms/OdtDocumentCreator_test/sandbox.txt
  0x0,0x0,0x0,0xf,
  0x44,
  0x3a,0x5c,0x71,0x74,0x5f,0x70,0x72,0x6f,0x67,0x72,0x61,0x6d,0x6d,0x73,
  
};

static const unsigned char qt_resource_name[] = {
  // sandbox.txt
  0x0,0xb,
  0x9,0x98,0x52,0xb4,
  0x0,0x73,
  0x0,0x61,0x0,0x6e,0x0,0x64,0x0,0x62,0x0,0x6f,0x0,0x78,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/sandbox.txt
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x90,0x36,0xf2,0x82,0xcd,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_customtreeview)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_customtreeview)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_customtreeview)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_customtreeview)()
{
    int version = 3;
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (version, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_customtreeview)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_customtreeview)(); }
   } dummy;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#endif
