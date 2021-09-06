#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIB"̳��"NOR, ({ "tan zi","tanzi"}));
        set_weight(1000);
        set_max_encumbrance(60);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����Ƶ�̳�ӡ�\n"+
                           "����������̳����װ(zhuang)һЩС���ӡ�\n");
                set("value", 499);
        }
        setup();
}

void init()
{
        add_action("do_zhuang","zhuang");
        add_action("do_noput","put");
}

int do_zhuang(string arg){
        string item,target;
        object ob,obj;
        

        if(!arg || sscanf(arg,"%s in %s",item,target)!=2)return notify_fail("�����ʽ��zhuang <����> in <̳��>��\n");
        if(!objectp(ob=present(target,this_player()))) return notify_fail("������û�����������\n"); 
        if(!objectp(obj=present(item,this_player()))) return notify_fail("������û�����������\n");
        if(!obj->query("cook/allow")) return notify_fail("���̳�ӣ�ֻ��װһЩ���档\n");
        if(ob->query("id")!="tan zi") return notify_fail("ֻ����̳��װ���档\n");
        if(ob->query_encumbrance()>=60) return notify_fail("���̳�ӣ��Ѿ�װ���³����ˡ�\n");
        message_vision("$N��һֻ"+(string)obj->query("name")+"װ��$n��\n",this_player(),ob);
        obj->move(ob);
        return 1;
        }

int do_noput(string arg) {
        string item, target;
        if(!arg) return notify_fail("��Ҫ��ʲô�����Ž����\n");
        if(sscanf(arg,"%s in %s",item,target)==2 && target == "tan zi"||target =="tanzi" ) {
          write("��ֻ���԰ѳ���װ(zhuang)��̳���\n");
          return 1; 
          }
}
