library identifier: 'shared_library@main', retriever: modernSCM(
[$class: 'GitSCMSource',
remote: 'https://github.com/Deepak-Sagar-007/shared_library.git']
)

pipeline {
agent { label 'linux-node1' }

```
options {
    timestamps()
}

environment {
    BUILD_DIR = 'build'
}

stages {

    stage('Checkout') {
        steps {
            checkout scm
        }
    }

    stage('Prepare') {
        steps {
            script {
                sh 'cmake --version'
                sh 'gcc --version'
            }
        }
    }

    stage('Build') {
        steps {
            sh '''
            mkdir -p ${BUILD_DIR}
            cd ${BUILD_DIR}
            cmake ..
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

    stage('Archive') {
        steps {
            archiveArtifacts artifacts: "${BUILD_DIR}/*", allowEmptyArchive: true
        }
    }
}
```

}
