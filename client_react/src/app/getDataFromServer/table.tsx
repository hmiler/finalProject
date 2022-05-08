




import * as React from 'react';
import Table from '@mui/material/Table';
import TableBody from '@mui/material/TableBody';
import TableCell from '@mui/material/TableCell';
import TableContainer from '@mui/material/TableContainer';
import TableHead from '@mui/material/TableHead';
import TableRow from '@mui/material/TableRow';
import Paper from '@mui/material/Paper';




export default function MyTable( {dataMessage,statusMessage}) {
  

  
  function creatStatus(
    type: number,
    status: number,
  ) {
    return { type, status };
  }


  function createData(
    type: number,
    distance: number,
    angle: number,
    speed: number,

  ) {
    return { type, distance ,angle,speed};
  }
  
 const rowsStatus = [...statusMessage];
 const rowsData = [...dataMessage];


 
let i=0;
  return (<>
  <h1 style={{fontSize: '50px',fontFamily: 'inherit', alignContent:"center",margin:"10px",color:'palevioletred'}}>messages from cameras!!</h1>
  <div style={{display:"inline-block"}}>
  <h3 >statys message</h3>
    <TableContainer component={Paper} style={{width: "430px",height:"500px" , display:"inline-block",margin:"10px"}}>
    <Table sx={{ minWidth: 150 }} aria-label="simple table">
      <TableHead>
        <TableRow style={{backgroundColor:'lightpink'}}>
        <TableCell align="left">type</TableCell>
          <TableCell align="left">status</TableCell>
        
        </TableRow>
      </TableHead>
      <TableBody>
        {rowsStatus.map((row) => (
          <TableRow
            key={i++}
            sx={{ '&:last-child td, &:last-child th': { border: 0 } }}
          >
           
            <TableCell align="left">{row.type}</TableCell>
            <TableCell align="left">{row.status}</TableCell>
          </TableRow>
        ))}
      </TableBody>
    </Table>
  </TableContainer>
  </div>
<div style={{display:"inline-block",float:'right'}}>
  <h3>discover message</h3>
  <TableContainer component={Paper} style={{width: "930px" ,height:"500px", display:"inline-block",margin:"10px",float:'right'}}>
    
    <Table sx={{ minWidth: 150 }} aria-label="simple table">
      <TableHead >
        <TableRow  style={{backgroundColor:'lightyellow'}}>
        <TableCell align="left" >type</TableCell>
          <TableCell align="left">distance:</TableCell>
          <TableCell align="left">angle:</TableCell>
          <TableCell align="left">speed:</TableCell>
         </TableRow>
      </TableHead>
      <TableBody>
        {rowsData.map((row) => (
          <TableRow
            key={i++}
            sx={{ '&:last-child td, &:last-child th': { border: 0 } }}
          >
           
            <TableCell align="left">{row.type}</TableCell>
            <TableCell align="left">{row.distance}</TableCell>
            <TableCell align="left">{row.angle}</TableCell>
            <TableCell align="left">{row.speed}</TableCell>

          </TableRow>
        ))}
      </TableBody>
    </Table>
  </TableContainer>
  </div>
  </>);
}
    