#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include "project.h"
#include "models/treemodel.h"
#include "models/namespacebarmodel.h"
#include "models/treeitem.h"
#include "declarationcolumnmodel.h"

namespace duly_gui {
    class Manager: public QObject
    {
        Q_OBJECT
        Q_PROPERTY(duly_gui::models::TreeModel *projectModel READ projectModel WRITE setProjectModel NOTIFY projectModelChanged)
        Q_PROPERTY(QVariant namespacebarModel READ namespacebarModel WRITE setNamespacebarModel NOTIFY namespacebarModelChanged)
        Q_PROPERTY(DeclarationModel *declarationModel READ declarationModel WRITE setDeclarationModel NOTIFY declarationModelChanged)
    public:
        Manager(QObject *parent = 0);
        virtual ~Manager();

        static const QString project_extension;

    private:
        void createTreeModel(Project *project);
        Project *m_project;
        void createNameSpaceModel(models::TreeItem *item);

    public:
        Q_INVOKABLE void createProject(const QString &, const QString &, const QString &);
        Q_INVOKABLE QJsonObject loadProjectData(const QString &);
        Q_INVOKABLE void openProject(const QString &);
        Q_INVOKABLE void openProject(Project *);
        Q_INVOKABLE QModelIndex getIndexMatch(duly_gui::models::TreeItem *index);
        Q_INVOKABLE QModelIndex getIndexMatchFromModel(duly_gui::models::Common *md);
        Q_INVOKABLE void selectTreeItem(const QModelIndex &index);
        Q_INVOKABLE void updateNamespace(const QModelIndex &index);
        Q_INVOKABLE void addContext(int index, int listindex);
        Q_INVOKABLE void addClass(int index, int listindex);
        Q_INVOKABLE void addFunction(int index, int listindex);
        Q_INVOKABLE void addVariable(int index, int listindex);

    signals:
        void projectModelChanged(models::TreeModel *model);
        void namespacebarModelChanged(const QVariant  &ref);
        void declarationModelChanged(DeclarationModel *ref);

    public:
        models::TreeModel *projectModel() const { return m_projectModel; }
        void setProjectModel(models::TreeModel *model);
        QVariant namespacebarModel() const { return m_namespacebarmodel; }
        void setNamespacebarModel(const QVariant &ref);
        void setDeclarationModel(DeclarationModel *ref);
        DeclarationModel * declarationModel() const { return m_declRef; }

    private:
         Project *loadProject(const QString &);
         models::TreeModel *m_projectModel;
         QVariant m_namespacebarmodel;
         models::TreeItem *m_currentPath;
         QVariant m_declarationModel;
         DeclarationModel *m_declRef;
         void setupClassModel(models::Class *cl, int level);
         void setupFunctionModel(models::Function *func);
         void setupContextModel(models::Context *context, int level);
         void setupVariableModel(models::Variable *variable);
         void createDeclarationModel(Project *project);
         void clearDeclarationModel();
         void createDeclarationIfMissing(models::Common *c);
    };
}

#endif // MANAGER_H
