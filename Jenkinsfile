pipeline {
    agent any

    stages {

        stage('Checkout') {
            steps {
                git 'https://github.com/YOUR_USERNAME/c-cmake-project.git'
            }
        }

        stage('Build') {
            steps {
                sh '''
                mkdir -p build
                cd build
                cmake ..
                make
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                cd build
                ctest
                '''
            }
        }
    }
}
