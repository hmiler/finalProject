import { ApiCore } from "../services/api/api-core";
import apiProvider from "../services/api/provider"

export default class testApiService extends ApiCore {
  constructor() {
      super({resource: './'});
  }

 public getData() {
        return apiProvider.getAll('data');
}

};
