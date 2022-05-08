import apiProvider from './provider';

export class ApiCore {
  resource: string;

  constructor(options) {
    this.resource = options.resource;
  }

  getAll = () => {
    return apiProvider.getAll(this.resource);
  };

  // getSingle = id => {
  //   return apiProvider.getSingle(this.resource, id);
  // };

  // post = model => {
  //   return apiProvider.post(this.resource, model);
  // };

  // put = model => {
  //   return apiProvider.put(this.resource, model);
  // };

  // patch = model => {
  //   return apiProvider.patch(this.resource, model);
  // };

  // remove = id => {
  //   return apiProvider.remove(this.resource, id);
  // };
}
