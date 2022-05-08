/**
 *
 * TestContent
 *
 */
import  React, { memo, useState } from 'react';
import { useTranslation } from 'react-i18next';
import { useEffect } from 'react';
import axios from 'axios';
import testApiService from '../myApi/test-api.service';
import MyTable from './table'


  export  function TestContent() {
  const { t, i18n } = useTranslation();
  const [dataMessage, setDataMessage] = useState([{}]);
  const [statusMessage, setStatusMessage] = useState([{id:0,name:""}]);

  useEffect(() => {
    loadData();

    setInterval(() => {
      loadData();
    }, 2000);
  }, []);

  const loadData = async () => {
    const response = await new testApiService().getData()
      .catch(error => {
        console.log(`errorrrrrrr: ${error}`);
      });
     let status = response.filter((obj:any)=>{ return obj.type==1});
    setStatusMessage(status);
    let data = response.filter((obj:any)=>{ return obj.type==2});
    setDataMessage(data);
    
  }


 

  return (<>
    <div  >
    <MyTable  dataMessage={dataMessage} statusMessage={statusMessage} />
   
</div>
 
  </>)
};



