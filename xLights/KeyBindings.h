//
//  KeyBindings.h
//  xLights
//

#ifndef __xLights__KeyBindings__
#define __xLights__KeyBindings__

#include "wx/wx.h"
#include "wx/filename.h"
#include <vector>

enum KeyBindingType {
    TIMING_ADD,
    TIMING_SPLIT,
    KEY_ZOOM_IN,
    KEY_ZOOM_OUT,
    RANDOM_EFFECT,
    EFFECT_STRING
};

class KeyBinding {
public:
    KeyBinding(unsigned char k, KeyBindingType t) : key(k), type(t), effectDataVersion() {
    }
    KeyBinding(unsigned char k, const wxString &name, const wxString &eff, const wxString &ver)
        : key(k), type(EFFECT_STRING), effectName(name), effectString(eff), effectDataVersion(ver) {
    }
    
    KeyBindingType GetType() const { return type; }
    unsigned char GetKey() const { return key; }
    const wxString &GetEffectString() const { return effectString;}
    const wxString &GetEffectName() const { return effectName;}
    const wxString &GetEffectDataVersion() const { return effectDataVersion;}
    
private:
    unsigned char key;
    KeyBindingType type;
    wxString effectName;
    wxString effectString;
    wxString effectDataVersion;
};

class KeyBindingMap {
public:
    KeyBindingMap() {}
    
    void LoadDefaults();
    
    void Load(wxFileName &file);
    void Save(wxFileName &file);
    
    KeyBinding *Find(unsigned char);
    
private:
    std::vector<KeyBinding> bindings;
};


#endif /* defined(__xLights__KeyBindings__) */
