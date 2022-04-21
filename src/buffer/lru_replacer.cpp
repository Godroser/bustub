//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// lru_replacer.cpp
//
// Identification: src/buffer/lru_replacer.cpp
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "buffer/lru_replacer.h"

namespace bustub {

LRUReplacer::LRUReplacer(size_t num_pages) {}

LRUReplacer::~LRUReplacer() = default;

bool LRUReplacer::Victim(frame_id_t *frame_id) {
    if (l_frames.size()==0) return false;
    else{
        for (std::list<frame_id_t>::iterator it = l_frames.begin(); it != l_frames.end(); it++){
            if (*frame_id==*it) {
                l_frames.remove(*it);
                return true;
            }
        }
    }
    return false;
}

void LRUReplacer::Pin(frame_id_t frame_id) {
    for (std::list<frame_id_t>::iterator it = l_frames.begin(); it != l_frames.end(); it++){
        if (frame_id==*it) {
            l_frames.remove(*it);
            return;
        }
    }
}

void LRUReplacer::Unpin(frame_id_t frame_id) {
    if (l_frames.size()<this->sizeframe){
        l_frames.push_back(frame_id);
    }
    else{
        l_frames.pop_front();
        l_frames.push_back(frame_id);
    }
    
    return;
}

size_t LRUReplacer::Size() {
    return this->sizeframe; 
}

}  // namespace bustub
