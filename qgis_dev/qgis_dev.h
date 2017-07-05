#ifndef QGIS_DEV_H
#define QGIS_DEV_H

#include <QtGui/QMainWindow>
#include "ui_qgis_dev.h"

#include "qgis_dev_browserdockwidget.h"
#include "qgis_devComposer.h"

#include <QList>
#include <QDockWidget>
#include <QProgressBar>
#include <QLabel>
#include <QDockWidget>
#include <QIcon>
#include <QStackedWidget>
#include <QTimer>

// QGis include
#include <qgsmapcanvas.h>
#include <qgsmaplayer.h>
#include <qgslayertreeview.h>
#include <qgslayertreemapcanvasbridge.h>
#include <qgsscalecombobox.h>
#include <qgsrendererv2.h>
#include <qgscomposermap.h>
#include <qgscomposerview.h>
#include <qgsraster.h>
#include <qgsmessagebar.h>
#include <qgsbrowsertreeview.h>

class qgis_dev_layerPropDialog;
class QgsMapTool;

class qgis_dev : public QMainWindow
{
    Q_OBJECT

public:
    qgis_dev( QWidget *parent = 0, Qt::WindowFlags flags = Qt::Window );
    ~qgis_dev();

    //! ���dock widget
    void addDockWidget( Qt::DockWidgetArea area, QDockWidget* dockwidget );

    //! ���ֵ�һʵ��
    static qgis_dev* instance() { return sm_instance; }

    //! �������ƻ�ȡ����ͼ��
    static QIcon getThemeIcon( const QString &theName );

    //! ��ȡ��ǰ map canvas
    QgsMapCanvas* mapCanvas() {return m_mapCanvas; }

    //! ��ȡ��ǰ��Ϣչʾ��
    QgsMessageBar* messageBar() {return m_infoBar;}

    //! ������Ϣ��ʾ����ʾ��ʱ��
    int messageTimeout();

    //! ��ʾ��ǰ�����������иı䣬��Ҫ����
    void markDirty();

    QString crsAndFormatAdjustedLayerUri( const QString& uri, const QStringList& supportedCrs, const QStringList& supportedFormats );

public slots:

    //! test��ʾ��ͬ��ʽ
    void testCatergorySymbol();

    //! ʸ��ͼ���ע����
    void testVecLayerLabel();
    //! ֱ�ӵ��ñ�ע���������
    void testUseLabelConfigDialog();

    //! ���ʸ��ͼ��
    void addVectorLayers();
    void addVectorLayer( QString vecLayerPath, QString basename, QString providerKey );
    //! ���դ��ͼ��
    void addRasterLayers();
    void addRasterLayer( QString rasterLayerPath, QString basename, QString providerKey );

    //! ���WMSͼ��
    void addWMSLayers();
    //! ���WCSͼ��
    void addWCSLayers();
    //! ���WFSͼ��
    void addWFSLayers();

    //! �½�ʸ��ͼ��
    void newVectorLayer();
    //! �½���ʱͼ��
    void newMemoryLayer();

    //! �Զ�ѡ���¼����ͼ��
    void autoSelectAddedLayer( QList<QgsMapLayer*> layers );

    //! �����Ա�
    void openAttributeTableDialog();

    //! �ı�ʸ��ͼ�����ʾ��ʽ
    void changeSymbol( QgsVectorLayer* layer, QgsFeatureRendererV2* featureRenderer );
    //! ��ʾ���ʹ��ʸ��ͼ����ʾ��ʽ
    void layerSymbolTest();

    //! �Ƴ�ͼ��
    void removeAllLayers();
    void removeLayer();

    //! ��ͼ���ߴ����¼�
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionPan_triggered();
    void on_actionIdentify_triggered();
    void on_actionActionNullMapTool_triggered(); // ���õ�ǰ��ͼ����Ϊ��

    //! �ͼ��ı䴥��
    void activeLayerChanged( QgsMapLayer* layer );

    //! ��ͼ�����ԶԻ���
    void showProperty();

    //! ��Ϣ����ʾ��Ϣ
    void showMessage( QString message, QgsMessageBar::MessageLevel level = QgsMessageBar::INFO );

private slots:
    //! ��ʾ���λ�õ�������
    void showMouseCoordinate( const QgsPoint & );
    //! ����ӥ��ͼ
    void createOverview();
    //! ��ʾ��ǰ��ͼ����
    void showScale( double theScale );
    //! �����û�ָ���������ŵ�ͼ
    void userScale();
    //! ������ʾ�û���������ʾ�������������
    void userCenter();

    //! ˢ�µ�ͼ��ʾ
    void refreshMapCanvas();

    //! ���ĵ�ͼ��λ , Ŀǰ������������ʾ�Ŀؼ��ϣ�δ��Ӧ�û�����ӿ�
    void mapUnitChange( int i );
    //! ��ѣЧ��
    void dizzy(); // ���Ч����qgis����Ա���ص����ַ�ʽ�ɣ�just for fun

    //! �������դ��ͼ�㹦��
    void addOpenSourceRasterLayer( const QString& url, const QString& basename, const QString& providerKey );
    //! ��� WFS ͼ��
    void addWFSLayer( const QString& url, const QString& typeName );

    #pragma region edit tool bar comand

    //! ����\�رձ༭ģʽ
    void on_actionToggle_Editing_triggered();
    //! �༭���ߴ����¼�
    void on_actionAdd_Feature_triggered();
    //! ����༭
    void on_actionSaveLayer_Edits_triggered();
    //! �ƶ�Ҫ��
    void on_actionMove_Feature_triggered();
    //! �ڵ㹤��
    void on_actionNode_Tool_triggered();
    //! ɾ����ѡҪ��
    void on_actionDelete_Selected_triggered();
    //! ���е�ǰҪ��
    void on_actionCut_Features_triggered();
    //! ���Ƶ�ǰҪ��
    void on_actionCopy_Features_triggered();
    //! ճ����ǰҪ��
    void on_actionPaste_Features_triggered();

    #pragma endregion

    #pragma region ��ʾդ��ͼ���һЩ����

    //! �ֲ�������ʾ
    void localHistogramStretch();
    //! ȫ��������ʾ
    void fullHistogramStretch();
    //! �ֲ��ۼƲü�������ʾ
    void localCumulativeCutStretch();
    //! ȫ���ۼƲü�������ʾ
    void fullCumulativeCutStretch();
    //! ������ʾ����
    void increaseBrightness();
    //! ������ʾ����
    void decreaseBrightness();
    //! ������ʾ�Աȶ�
    void increaseContrast();
    //! ������ʾ�Աȶ�
    void decreaseContrast();

    #pragma endregion

private:
    Ui::qgis_devClass ui; // ������UI
    static qgis_dev* sm_instance;

    // ��ͼ����
    QgsMapTool* m_mapToolZoomIn;
    QgsMapTool* m_mapToolZoomOut;
    QgsMapTool* m_mapToolZoomFull;
    QgsMapTool* m_mapToolPan;
    QgsMapTool* m_mapToolIdentify;

    QStackedWidget* m_stackedWidget; // ����mapcanvas��mapComposor���л�
    QComboBox* pageViewComboBox;

    QgsMapCanvas* m_mapCanvas; // ��ͼ����
    qgis_dev_browserDockWidget* m_browserDockWight; // �ļ�������
    QgsLayerTreeView* m_layerTreeView;// ͼ�������
    QgsLayerTreeMapCanvasBridge *m_layerTreeCanvasBridge; // ����ͼ��������͵�ͼ����������
    qgis_dev_layerPropDialog* m_layerPropDialog;

    QDockWidget *m_layerTreeDock; // װͼ�������
    QDockWidget *m_layerOrderDock;
    QDockWidget *m_OverviewDock; // װӥ��ͼ
    QDockWidget *m_pGpsDock;
    QDockWidget *m_logDock;

    QLabel* m_scaleLabel; // ��״̬������ʾ��scale 1:��
    QgsScaleComboBox* m_scaleEdit; //! ��״̬������ʾ������ֵ
    QProgressBar* m_progressBar;
    QLabel* m_coordsLabel; // ��״̬����ʾ"Coordinate / Extent"
    QLineEdit* m_coordsEdit; // ��״̬����ʾ��������

    QList<QgsMapCanvasLayer> mapCanvasLayerSet; // ��ͼ�������õ�ͼ�㼯��

    QCursor* m_overviewMapCursor; // ӥ��ͼ�õ����ָ��

    unsigned int m_MousePrecisionDecimalPlaces; // ָ���������С����λ��

    qgis_devComposer* m_composer; // ��ͼ��ͼģ��

    //! Helps to make people dizzy
    QTimer* m_dizzyTimer;

    QgsMessageBar* m_infoBar; // �ڵ�ͼ��������ʾ��Ϣ

//=== Private Member Functions ===
    #pragma region private member functions

    //! ��ʼ��ͼ�������
    void initLayerTreeView();
    //! ����״̬��
    void createStatusBar();

    //! ��ʼ����ͼ����
    void createMapTools();

    //! ������ӡ��ͼ��ͼ
    void createComposer();
    //! ��ȡ��ǰѡ��ͼ��
    QgsMapLayer* activeLayer();

    //! ���ڻ�ȡimages��Դ�⵱�е�Icon·��
    static const QString activeThemePath();
    static const QString defaultThemePath();

    //! ֱ��ͼ����
    void histogramStretch( bool visibleAreaOnly = false, QgsRaster::ContrastEnhancementLimits theLimits = QgsRaster::ContrastEnhancementMinMax );
    //! �Աȶȵ���, updateBrightness�������Ƶ����Աȶ�ʱ�Ƿ���Ҫͬʱ��������
    void adjustBrightnessContrast( int delta, bool updateBrightness = true );

    //! ����դ��ͼ�����
    void enableRasterTools( bool val );

    //! ����ʸ��ͼ�����
    void enableVectorTools( bool val );

    #pragma endregion private member functions
};

#endif // QGIS_DEV_H
