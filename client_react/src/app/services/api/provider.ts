import axios from 'axios';
import { handleResponse, handleError } from './response';
 

const BASE_URL = process.env.REACT_APP_API_ADDRESS;
/** @param {string} resource */
const getAll = resource => {
  return axios
    .get(`${BASE_URL}/${resource}`)
    .then(handleResponse)
    .catch(handleError);
};

/** @param {string} resource */
const get = (resource) => {
  return axios
    .get(`${BASE_URL}/${resource}`)
    .then(handleResponse)
    .catch(handleError);
};

// /** @param {string} resource */
// /** @param {string} id */
// const getSingle = (resource, id) => {
//   return axios
//     .get(`${BASE_URL}/${resource}/${id}`)
//     .then(handleResponse)
//     .catch(handleError);
// };

// /** @param {string} resource */
// /** @param {object} model */
// const post = (resource, model) => {
//   return axios
//     .post(`${BASE_URL}/${resource}`, model)
//     .then(handleResponse)
//     .catch(handleError);
// };

// /** @param {string} resource */
// /** @param {object} model */
// const put = (resource, model) => {
//   return axios
//     .put(`${BASE_URL}/${resource}`, model)
//     .then(handleResponse)
//     .catch(handleError);
// };

// /** @param {string} resource */
// /** @param {object} model */
// const patch = (resource, model) => {
//   return axios
//     .patch(`${BASE_URL}/${resource}`, model)
//     .then(handleResponse)
//     .catch(handleError);
// };

// /** @param {string} resource */
// /** @param {string} id */
// const remove = (resource, id) => {
//   return axios
//     .delete(`${BASE_URL}/${resource}`, id)
//     .then(handleResponse)
//     .catch(handleError);
// };

const apiProvider = {
  get,
   getAll,
  // getSingle,
  // post,
  // put,
  // patch,
  // remove,
};

export default apiProvider;
