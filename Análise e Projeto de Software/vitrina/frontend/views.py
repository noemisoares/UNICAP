from django.shortcuts import render, redirect
from django.contrib.auth.models import User
from django.contrib.auth import authenticate, login as auth_login

def homepage_view(request):
    return render(request, 'homepage.html')

def login_view(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        senha = request.POST.get('senha')
        user = authenticate(request, username=username, password=senha)
        if user is not None:
            auth_login(request, user)
            return redirect('homepage')
        else:
            return render(request, 'login.html', {'mensagem': 'Usuário ou senha inválidos.'})
    return render(request, 'login.html')

def cadastro_view(request):
    if request.method == 'POST':
        username = request.POST.get('username')
        email = request.POST.get('email')
        senha = request.POST.get('senha')
        user = User.objects.create_user(username=username, email=email, password=senha)
        user.save()
        return redirect('login')
    return render(request, 'cadastro.html')

def perfil_view(request):
    return render(request, 'perfil.html')

def telaescolha_view(request):
    return render(request, 'telaescolha.html')

def vitrine_view(request):
    return render(request, 'vitrine.html')