#ifndef GLDDISKINFOUTILS_H
#define GLDDISKINFOUTILS_H

#include <qt_windows.h>
#include <bitset>
#include <Winioctl.h>
#include <QVector>
#include <QString>

using namespace std;

namespace GlodonDiskInfo
{
    enum FS
    {
        OTHER_FORMAT = 0,
        FAT32        = 1,
        NTFS         = 2
    };

    typedef struct DiskInfomation
    {
        DiskInfomation()
        {
            m_dwFreeMBytes = 0;
            m_dwTotalMBytes = 0;
        }

        QString      m_strDiskName;   // 分区名(盘符)
        QString      m_strTypeName;   // 分区类型
        QString      m_strFileSystem; // 分区格式
        qulonglong   m_dwTotalMBytes; // 总空间
        qulonglong   m_dwFreeMBytes;  // 可用空间

    }DiskInfomation;

    class GLDDiskInfo
    {
    public:

        /**
         * @brief 获取系统盘符
         * @return
         */
        QString getSystemVolumeName();

        /**
         * @brief 获取当前盘符
         * @return
         */
        QString getCurrentVolumeName();

        /**
         * @brief 获取硬盘序列号
         * @return
         */
        QString getPhysicalDriveSerialNumber();

        /**
         * @brief 获取分区个数
         * @return
         */
        ulong getVolumeNum();

        /**
         * @brief 获取所有分区信息
         * @return
         */
        QVector<DiskInfomation> getAllVolumeInfo();

        /**
         * @brief 获取分区格式
         * @param dir  分区名
         * @return
         */
        FS getFileSystemType(const QString& dir);

        /**
         * @brief 获取分区类型
         * @param dir   分区名
         * @return
         */
        QString getVolumeTypeItem(const QString& dir);

        /**
         * @brief 获取分区空间信息
         * @param dir                      分区名
         * @param ri64FreeBytesToCaller    可用空间
         * @param ri64TotalBytes           分区总空间
         * @return
         */
        bool getVolumeSpace(const QString& dir, qulonglong& ri64FreeBytesToCaller, qulonglong& ri64TotalBytes);

        /**
        * @brief 获取硬盘空间信息
        * @param ri64FreeBytesToCaller    硬盘可用空间
        * @param ri64TotalBytes           硬盘总空间
        * @return
        */
        bool getDiskSpaceInfo(qulonglong& ri64FreeBytesToCaller, qulonglong& ri64TotalBytes);

    private:
        bool getAllVolumeName(ulong dwDrvNum, QVector<QString> & volumeNameVct);
    };
}

#endif // GLDDISKINFOUTILS_H
