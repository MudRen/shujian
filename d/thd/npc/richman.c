inherit NPC;

#include <ansi.h>

string ask_laozu();

string * name1 = ({ "��","Ǯ","��","��","��","��","֣","��","��","��"}); 
string * name2 = ({ "��","��","��","��","ɽ","ƽ","��","ʿ","��","��"}); 
string * id = ({ "gon zi", "nan zi", "qing nian", "young man"});

void create()
{
        string name = name1[random(sizeof(name1))] + name2[random(sizeof(name2))];
        string id = id[random(sizeof(id))];
        set_name(name, ({ id }));
        set("gender", "����");
        set("age", 15 + random(5));
        set("long", "���Ǹ��������ӣ������������ǻ�����\n");
        set("combat_exp", 10000);
        set("meitude", "peaceful");
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("max_neili", 1000);
        set("neili", 1000);
        setup();
        carry_object(ARMOR_D("mr_cloth1"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        if (random(5))
               carry_object("/d/thd/obj/art");
          add_money("gold", random(3)+5);
}

