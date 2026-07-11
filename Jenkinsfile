library identifier: 'shared_library@main', retriever: modernSCM(
[$class: 'GitSCMSource',
remote: 'https://github.com/Deepak-Sagar-007/shared_library.git']
)

pipeline {
    agent { label 'linux-node1' }

    environment {
        BUILD_DIR = 'build'
    }

    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Install Tools') {
            steps {
                sh '''
                sudo apt update || true
                sudo apt install -y cmake gcc-arm-none-eabi || true
                '''
            }
        }

        stage('Build') {
            steps {
                sh '''
              mkdir -p build
               cd build
               cmake .. -DCMAKE_TOOLCHAIN_FILE=../arm-gcc-toolchain.cmake
                make
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                cd ${BUILD_DIR}
                ctest || true
                '''
            }
        }

        stage('Verify Artifacts') {
            steps {
                sh 'ls -lh ${BUILD_DIR}'
            }
        }

        stage('Archive') {
            steps {
                archiveArtifacts artifacts: 'build/*.elf, build/*.hex, build/*.bin', allowEmptyArchive: true
            }
        }
    }
}
