#ifndef QGIS_DEVATTRTABLEDIALOG_H
#define QGIS_DEVATTRTABLEDIALOG_H

#include <QDialog>
#include "ui_qgsattributetabledialog.h"

#include <QDockWidget>
#include <QSignalMapper>

#include <qgsvectorlayer.h>
#include <qgsfieldmodel.h>
#include <qgsrubberband.h>

// ���Ա�Ի���
class qgis_devattrtableDialog : public QDialog, public Ui::QgsAttributeTableDialog
{
    Q_OBJECT

public:
    qgis_devattrtableDialog( QgsVectorLayer* theVecLayer, QWidget *parent = 0, Qt::WindowFlags flags = Qt::Window );
    ~qgis_devattrtableDialog();

    /**
    * Sets the filter expression to filter visible features
    * @param filterString filter query string. QgsExpression compatible.
    */
    void setFilterExpression( QString filterString );

public slots:
    void editingToggled(); // Toggles editing mode

signals:
    //! ��ͼ��༭״̬����Ϣ
    void editingToggled( QgsMapLayer* layer );
    //! ���������Ϣ
    void saveEdits( QgsMapLayer* layer );

private slots:
    /// ==== ��ť�¼� ====
    //! ����ѡ�����
    void on_mCopySelectedRowsButton_clicked();
    //! �л��༭ģʽ
    void on_mToggleEditingButton_toggled();
    //! ����༭
    void on_mSaveEditsButton_clicked();

    //! ��ѡ
    void on_mInvertSelectionButton_clicked();
    //! ���ѡ��
    void on_mRemoveSelectionButton_clicked();
    //! ���ŵ���ѡ�����
    void on_mZoomMapToSelectedRowsButton_clicked();
    //! ���ε���ѡ��
    void on_mPanMapToSelectedRowsButton_clicked();
    //! �ƶ�ѡ���е�����
    void on_mSelectedToTopButton_toggled();

    //! ��������ԶԻ���
    void on_mAddAttribute_clicked();

    //! ���Ƴ����ԶԻ���
    void on_mRemoveAttribute_clicked();
    //! ���ֶμ�����
    void on_mOpenFieldCalculator_clicked();

    //! ɾ��ѡ���Ҫ��
    void on_mDeleteSelectedButton_clicked();

    //! ������״̬�ı�ʱ����������Ա�״̬�л�����ͼ״̬�������Ĳ˵��ϰ�ť��״̬
    void on_mMainView_currentChanged( int );

    //! ���Ҫ��
    void on_mAddFeature_clicked();
    //! ����
    void on_mHelpButton_clicked();

    //! �򿪸������Բ�ѯҪ�ضԻ���
    void on_mExpressionSelectButton_clicked();

    //! �������Դ��ڱ���
    void updateTitle();

    //! ���˱��ʽ���������� advanced filter ����
    void filterExpressionBuilder();
    //! ������ʾ����Ҫ��
    void filterShowAll();
    //! ���˽���ʾ��ѡ��Ҫ��
    void filterSelected();
    //! ���˽���ʾ�ɼ�Ҫ��
    void filterVisible();
    //! ���˽���ʾ�ѱ༭Ҫ��
    void filterEdited();
    //! �����и����¼�
    void filterColumnChanged( QObject* filterAction );
    //! ���˲�ѯ�����¼�
    void filterQueryChanged( const QString& query );
    //! Ӧ�ù��˲�ѯ
    void filterQueryAccepted();

    //! �ֶ����Ƴ�ʼ���ֶ���ʾ�б�
    void columnBoxInit();

    //! ִ���ֶμ�����
    void runFieldCalculation( QgsVectorLayer* layer, QString fieldName,
                              QString expression, QgsFeatureIds filteredIds = QgsFeatureIds() );
    //! �����û������Expression�����ֶ�
    void updateFieldFromExpression();
    //! �����û�ѡ���feature�������Expression�����ֶ�
    void updateFieldFromExpressionSelected();
    //! ���°�ť״̬
    void updateButtonStatus( QString fieldName, bool isValid );
private:

    QMenu* mMenuActions; // �˵�����
    QAction* mActionToggleEditing; // �༭����

    QDockWidget* mDock; // ʹ�����Ա��ڿ�Dock
    QgsDistanceArea* myDa;

    QMenu* mFilterColumnsMenu;
    QSignalMapper* mFilterActionMapper;

    QgsVectorLayer* mLayer; // ��ʾ��ͼ���������Ϣ
    QgsFieldModel* mFieldModel; // �ֶ�����ģ��

    QgsRubberBand* mRubberBand;
};

#endif // QGIS_DEVATTRTABLEDIALOG_H
