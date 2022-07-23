from . import views
from django.urls import path

urlpatterns = [
    path('', views.index, name='index'),
    path('create', views.create, name='create'),
    path('list', views.list, name='list'),
    path('fileupload', views.fileupload, name='fileupload'),
    path('edit/(?P<id>\d+)', views.edit, name='edit'),
    path('edit/update/(?P<id>\d+)', views.update, name='update'),
    path('delete/(?P<id>\d+)', views.delete, name='delete'),
    path('register/', views.register,name='register'),
    path('register/success/',views.register_success,name='register_success'),
    path('users/',views.users,name='users'),
    path('users/delete/(?P<id>\d+)', views.user_delete, name='user_delete'),
    path('change_password', views.changePassword, name='changePassword'),
    path('file/delete', views.changePassword, name='changePassword'),
    path('file/delete/(?P<id>\d+)', views.deleteFiles, name='deleteFiles'),
]