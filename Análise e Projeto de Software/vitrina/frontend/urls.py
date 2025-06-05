from django.urls import path
from django.conf import settings
from django.conf.urls.static import static
from . import views

urlpatterns = [
    path('', views.homepage_view, name='homepage'),             # homepage.html
    path('login/', views.login_view, name='login'),             # login.html
    path('cadastro/', views.cadastro_view, name='cadastro'),    # cadastro.html
    path('perfil/', views.perfil_view, name='perfil'),          # perfil.html
    path('escolha/', views.telaescolha_view, name='telaescolha'), # telaescolha.html
    path('vitrine/', views.vitrine_view, name='vitrine'),       # vitrine.html
]

if settings.DEBUG:
    urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)