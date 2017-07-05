#ifndef QGIS_DEV_LABEL_H
#define QGIS_DEV_LABEL_H

#include <QObject>
#include <QDialog>
#include <ui_qgis_dev_layerPropDialog.h>
#include <qgis_dev_labelinggui.h>

class QgsVectorLayer;
class QgsMapCanvas;
class QTreeWidgetItem;

//! ������ʾʸ��ͼ�������
class qgis_dev_layerPropDialog : public QDialog , public Ui::qgis_dev_layerPropDialog
{
    Q_OBJECT

public:
    qgis_dev_layerPropDialog( QWidget *parent, QgsVectorLayer* layer, QgsMapCanvas* mapCanvas );
    ~qgis_dev_layerPropDialog();

    //! ���һ�����Ե�ѡ���б��У�������һ���������ɫ
    void addAttribute( QTreeWidgetItem* item );

public slots:
    void apply();

    //! ͸���Ȼ�������ֵ
    void on_mTransparencySlider_valueChanged( int value );
    //! ������ఴť�����¼�
    void on_mAddCategoryPushButton_clicked();
    //! ɾ�����ఴť�����¼�
    void on_mRemoveCategoryPushButton_clicked();
    //! ���Դ����е�Ԫ��˫���¼�
    void on_mAttributesTreeWidget_itemDoubleClicked( QTreeWidgetItem * item, int column );
    //! �������ֵ��С��ť�¼�
    void on_mFindMaximumValueButton_clicked();
    //! ��ʾͼ��checkbox�¼�
    void on_mDisplayDiagramsGroupBox_toggled( bool checked );
    //! ͼ�������б���Ԫ��˫���¼�
    void on_mDiagramAttributesTreeWidget_itemDoubleClicked( QTreeWidgetItem * item, int column );
    //!
    void on_mEngineSettingsButton_clicked();
    //! ��ʾ��С���Ա��ʽ����
    void showSizeAttributeExpressionDialog();
    //! ������Ա��ʽ����
    void showAddAttributeExpressionDialog();

private slots:
    //! ȷ����ť�¼�
    void settingsIsOk();

    //! ��ע
    void ifDisLabel( int dis );

    //! ͼ��
    void enableDiagram();

    void diagramChanged( int index );

    //! ѡ��ͼ������ɫ
    void on_mBackgroundColorButton_clicked();
    //! ѡ��ͼ������ɫ
    void on_mDiagramPenColorButton_clicked();

private:
    //! ��ǰͼ��ָ��
    QgsVectorLayer* m_layer;
    //! ��ͼ����ָ��
    QgsMapCanvas* m_mapCanvas;

    qgis_dev_labelingGui* labelingGui;

    int m_availableAttributeCount;

    //! ��ʼ����״ͼ����UI
    void setupBarUI();
    //! ��ʼ����״ͼ����UI
    void setupPieUI();
    //! ��ʼ���ı�ͼ����UI
    void setupTextUI();

    //! ��ʼ�������ֶ�ѡ�����
    void initAttributeSelection();


    //! ��������
    void setGenericProperty();

    //! ��ʽ����
    void setStyleProperty();

    //! �ֶ�����
    void setFieldProperty();

    //! ͼ������
    void setDiagramProperty();

    //! ��ע����
    void setLableProperty();
};


#endif // QGIS_DEV_LABEL_H
