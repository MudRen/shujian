// by lsxk@hsbbs 2007/9/26
inherit ITEM;
inherit F_AUTOLOAD;
#include <ansi.h>

string strSN;
void mapping_sn(object);

void create(object me,string arg)
{
        set_name(HIY "��Ʊ��" NOR, ({"cai piao","caipiao"}));
        set("unit", "��");
        set("long", "����һ�����������ƾ֤�������������鿴(read)�������й����������š�\n");
        set("value", 0);
        set("no_drop","����drop [caipiao|cai piao]������!");
        set("no_give",1);
        setup();
}

void init()
{
    object me = this_player();
    add_action("do_drop","drop");
    if(!me->query("caipiao")) return;

    mapping_sn(me);
    add_action("do_check","read");
}

int do_drop(string arg)
{
     object me = this_player();

     if(!arg) return notify_fail("��Ҫ��ʲô?\n");

     if(arg!="caipiao" && arg!="cai piao") return 0;

     me->delete("caipiao");
     me->delete("caipiao_id");
     message_vision(HIC"$N�����Ե���һ��"+HIY+"��Ʊ��"+HIC+"!\n"NOR,me);
     destruct(present("cai piao", me));

    return 1;
}

void mapping_sn(object me)
{
    int i, k;
    mapping my_caipiao;
    //string strTemp;

    my_caipiao = me->query("caipiao");
    i = sizeof(me->query("caipiao"));
    strSN = "������������������ŵĲ�Ʊ��\n";

    for(k = 0;k<i;k++){
        strSN += "��"+chinese_number(k+1)+"�ţ���ţ�"+HIC+me->query("caipiao/��"+chinese_number(k+1)+"��/my_caipiao")+NOR+"  ������ң�"+HIY+me->query("caipiao/��"+chinese_number(k+1)+"��/huobi")+"\n"NOR;
    }
}

int do_check(string arg)
{
    object me = this_player();

    if(!arg) return notify_fail("��Ҫ��ʲô?\n");

    if(arg!="caipiao" && arg!="cai piao") return notify_fail("��Ҫ��ʲô?\n");

    if(!me->query("caipiao")){
        message_vision("$N���˿����Ų�Ʊ�����ֲ����Լ���ģ����־������˽ֱߡ�\n",me);
        destruct(this_object());
        return 1;
    }

    mapping_sn(me);
    tell_object(me, strSN);
    return 1;
}

int query_autoload() { return 1; }

