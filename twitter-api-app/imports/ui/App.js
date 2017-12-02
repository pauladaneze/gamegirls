import React, { Component } from 'react';
import Display from './Display.js'; 



export default class App extends Component {

  getAsteroids() {
    return [
      { _id: 1, text: 'metoo' },
      { _id: 2, text: 'metoo' },
      { _id: 3, text: 'metoo3' },


    ];
  }




  renderAsteroids() {
    return this.getAsteroids().map((asteroid) => (
      <Display key={asteroid._id} asteroid={asteroid} />
    ));
  }

  render() {
    return (
      <div className="container">
        <header>
          <h1>#metoo</h1>
        </header>

        <ul>
         {this.renderAsteroids()}
        </ul>
      </div>
    );
  }
}


 


