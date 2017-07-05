#ifndef QGIS_DEV_BROWSERDOCKWIGHT_H
#define QGIS_DEV_BROWSERDOCKWIGHT_H

#include <QDockWidget>
#include <ui_qgsbrowserdockwidgetbase.h>

#include <QModelIndex>
#include <QShowEvent>

class QgsLayerItem;
class QgsBrowserModel;
class QModelIndex;
class qgis_dev_dockBrowserTreeView;
class QgsDataItem;
class qgis_dev_browserTreeFilterProxyModel;

//! �ļ������dock widget�࣬�ṩ�ļ�����������ļ������ͼ��Ȼ�������
class qgis_dev_browserDockWidget : public QDockWidget, private Ui::QgsBrowserDockWidgetBase
{
    Q_OBJECT

public:
    qgis_dev_browserDockWidget( QString name, QWidget *parent = 0 );
    ~qgis_dev_browserDockWidget();

    //! ���ָ��·�����ղ�
    void addFavouriteDirectory( QString favDir );

public slots:
    //! ���ѡ�е�ͼ��
    void addLayerAtIndex( const QModelIndex& index );
    //! �Ҽ��˵�
    void showContextMenu( const QPoint& );

    //! ��ӵ��ղ�
    void addFavourite();
    //! ���Ŀ¼���ղ�
    void addFavouriteDirectory();
    //! �Ƴ��ղ�
    void removeFavourite();

    //! ˢ��
    void refresh();

    //! ��ʾ���������
    void showFilterWidget( bool visible );
    void setFilterSyntax( QAction* action );
    //! ���ô�Сд����
    void setCaseSensitive( bool caseSensitive );
    //! ���ù�����
    void setFilter();

    //==== ͼ�������Ҽ��˵����� ====
    //! ��ӵ�ǰͼ��
    void addCurrentLayer();
    //! ���ѡ�е�����ͼ��
    void addSelectedLayers();
    //! ��ʾ������Ϣ
    void showProperties();
    //! �л�����ɨ��
    void toggleFastScan();

protected:
    void refreshModel( const QModelIndex& index );
    //! ��д showEvent ���������������ʼ�� m_model �ȶ���
    void showEvent( QShowEvent* event ) override;
    void addLayer( QgsLayerItem* layerItem );

    qgis_dev_dockBrowserTreeView* m_browserView; // �ļ������view
    QgsBrowserModel* m_model; // �ļ������model
    qgis_dev_browserTreeFilterProxyModel* m_proxyModel; // �ļ����������model
    QString m_initPath; // ��ʼ·��

};

#endif // QGIS_DEV_BROWSERDOCKWIGHT_H
