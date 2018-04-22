教程地址: http://hyperledger-fabric.readthedocs.io/en/latest/build_network.html 


./byfn.sh generate

这个命令，由3个子命令。
  generateCerts
  replacePrivateKey
  generateChannelArtifacts
 
function generateCerts (){
  which cryptogen
  if [ "$?" -ne 0 ]; then
    echo "cryptogen tool not found. exiting"
    exit 1
  fi
  echo
  echo "##########################################################"
  echo "##### Generate certificates using cryptogen tool #########"
  echo "##########################################################"

  if [ -d "crypto-config" ]; then
    rm -Rf crypto-config
  fi
  set -x
  cryptogen generate --config=./crypto-config.yaml
  res=$?
  set +x
  if [ $res -ne 0 ]; then
    echo "Failed to generate certificates..."
    exit 1
  fi
  echo
}  

实际是执行`cryptogen generate --config=./crypto-config.yaml`

生成的目录结构。

replacePrivateKey()
就是把生成的key更新到配置文件里。

configtxgen -profile TwoOrgsOrdererGenesis -outputBlock ./channel-artifacts/genesis.block
configtxgen -profile TwoOrgsChannel -outputCreateChannelTx ./channel-artifacts/channel.tx -channelID $CHANNEL_NAME
configtxgen -profile TwoOrgsChannel -outputAnchorPeersUpdate ./channel-artifacts/Org1MSPanchors.tx -channelID $CHANNEL_NAME -asOrg Org1MSP
configtxgen -profile TwoOrgsChannel -outputAnchorPeersUpdate ./channel-artifacts/Org2MSPanchors.tx -channelID $CHANNEL_NAME -asOrg Org2MSP




./byfn.sh up -i 1.1.0 这里-i可以指定版本号，默认是latest，有些容器没有这个tag。
```
  if [ "${IF_COUCHDB}" == "couchdb" ]; then
    IMAGE_TAG=$IMAGETAG docker-compose -f $COMPOSE_FILE -f $COMPOSE_FILE_COUCH up -d 2>&1
  else
    IMAGE_TAG=$IMAGETAG docker-compose -f $COMPOSE_FILE up -d 2>&1
  fi
```  
会跑起来这么多容器：
CONTAINER ID        IMAGE                                                                                                  COMMAND                  CREATED             STATUS              PORTS                                              NAMES
4048ec81ffc4        dev-peer1.org2.example.com-mycc-1.0-26c2ef32838554aac4f7ad6f100aca865e87959c9a126e86d764c8d01f8346ab   "chaincode -peer.a..."   11 minutes ago      Up 11 minutes                                                          dev-peer1.org2.example.com-mycc-1.0
6f263b609c04        dev-peer0.org1.example.com-mycc-1.0-384f11f484b9302df90b453200cfb25174305fce8f53f4e94d45ee3b6cab0ce9   "chaincode -peer.a..."   11 minutes ago      Up 11 minutes                                                          dev-peer0.org1.example.com-mycc-1.0
945c6109dd06        dev-peer0.org2.example.com-mycc-1.0-15b571b3ce849066b7ec74497da3b27e54e0df1345daff3951b94245ce09c42b   "chaincode -peer.a..."   11 minutes ago      Up 11 minutes                                                          dev-peer0.org2.example.com-mycc-1.0
bf1a15cd2c09        hyperledger/fabric-tools:x86_64-1.1.0                                                                  "/bin/bash"              12 minutes ago      Up 2 minutes                                                           cli
a8452b4fb9f4        hyperledger/fabric-peer:x86_64-1.1.0                                                                   "peer node start"        12 minutes ago      Up 12 minutes       0.0.0.0:7051->7051/tcp, 0.0.0.0:7053->7053/tcp     peer0.org1.example.com
19c175628f73        hyperledger/fabric-peer:x86_64-1.1.0                                                                   "peer node start"        12 minutes ago      Up 12 minutes       0.0.0.0:10051->7051/tcp, 0.0.0.0:10053->7053/tcp   peer1.org2.example.com
9e224ffa7baf        hyperledger/fabric-peer:x86_64-1.1.0                                                                   "peer node start"        12 minutes ago      Up 12 minutes       0.0.0.0:9051->7051/tcp, 0.0.0.0:9053->7053/tcp     peer0.org2.example.com
753c3ef132ec        hyperledger/fabric-peer:x86_64-1.1.0                                                                   "peer node start"        12 minutes ago      Up 12 minutes       0.0.0.0:8051->7051/tcp, 0.0.0.0:8053->7053/tcp     peer1.org1.example.com
c1a41a378baf        hyperledger/fabric-orderer:x86_64-1.1.0                                                                "orderer"                12 minutes ago      Up 12 minutes       0.0.0.0:7050->7050/tcp                             orderer.example.com





最终执行这个测试脚本：
docker exec cli scripts/script.sh $CHANNEL_NAME $CLI_DELAY $LANGUAGE $CLI_TIMEOUT

scripts/script.sh
import了这个scripts/utils.sh
