// Copyright 2019 Rica Radu Leonard
// Copyright 2019 Ciobanu Bogdan-Calin
#pragma once

#include <vector>
#include "../include/Matrix.h"
#include "../include/ActivationFunction.h"

template <class T>
class NeuralNetwork {
   public:
    NeuralNetwork(int _inputNeurons, int _hiddenLayers,
                  std::vector<int> _hiddenLayersSizes, int _outputNeurons,
                  double _learningRate) {
    };
                  
    void Train(const std::vector<int> &input, int correctValue) {};

    int Classify(const std::vector<int> &input) const {};

   private:
    template <class sigmoid, class biasType = long double>
    class HiddenLayer {
    public:
        HiddenLayer() {}
        
        HiddenLayer(const size_t &_size, const size_t &_nextLayerSize) {}
        
        HiddenLayer(const HiddenLayer &target) {
            *this = target;
        }
        
        HiddenLayer(HiddenLayer &&target) {
            *this = target;
        }
        
        HiddenLayer &operator=(const HiddenLayer &target) {
            size = target.size;
            nextLayerSize = target.nextLayerSize;
            activations = target.activation;
            bias = target.bias;
            weights = target.weights;
        }
        
        HiddenLayer &operator=(HiddenLayer &&target) {
            size = std::move(target.size);
            nextLayerSize = std::move(target.nextLayerSize);
            activations = std::move(target.activations);
            bias = std::move(target.bias);
            weights = std::move(target.weights);
        }
        
        Matrix<long double> &GetActivations() {
            return activations;
        }
        
        Matrix<biasType> &GetBias() {
            return bias;
        }
        
        Matrix<long double> &GetWeights() {
            return weights;
        }
        
        Matrix<long double> &&ComputeNextLayer() {
            Matrix<long double> retval;
            auto sigma = [=, &retval] (const Matrix<long double> &target) {
                for (auto &it : target)  /// TODO Rica
                    it = sigmoid(it);
            };
            
            retval = sigma(weights * activations + bias);
        }
        
        Matrix<long double> &&SetWeights(Matrix<long double> &&target) {
            weights = std::move(target);
        }
        
        Matrix<biasType> &&SetBias(Matrix<biasType> &&target) {
            bias = std::move(target);
        }
        
        Matrix<long double> &&SetActivations(Matrix<long double> &&target) {
            activations = std::move(target);
        }
        
        ~HiddenLayer() {}

    private:
        size_t size, nextLayerSize;
        Matrix<long double> activations, weights;
        Matrix<biasType> bias;
    };
       
    int inputNeurons;
    int hiddenLayers;
    std::vector<int> hiddenLayersSizes;
    int ouputNeurons;
    double learningRate;
};
