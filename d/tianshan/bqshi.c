// Room: /d/tianshan/bqshi.c
// By Linux

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "������");
	set("long", @LONG
���������չ����Ӱڷű����ķ��䣬�������ҵض���һЩ�����е��Ѿ���
�ư߰��ˣ��еĻ��Ƿ���͸���������Ÿ��ֱ����ı����ܣ�jia)�ڷ��ڷ����
���С���������˸��ֱ����ͷ��ߣ�����ѣĿ�����չ�����������ʱ�򣬾͵�
��������ѡ���С�
LONG);
	set("exits", ([
		"north" : __DIR__"zoulang2",
        ]));

	set("item_desc", ([
                "jia" : "����һ��ר�������Ÿ��ֱ����ļ��ӡ�\n"+
                        "�����У�\n\n"+
                        "       ��(bian)��        ��(chui)�� \n"+
                        "       ��(gun)��         ��(bang)�� \n"+
                        "       ��(zhang)��       ��(sword)��\n"+
                        "       ��(dao)��         ��(ling)��  \n"+
                        "       ����(armor)��\n"+
                        "���������������(na)��ʹ�ã�Ҳ���԰Ѳ�Ҫ�ı�����(fang)�����棬\n"+
                        "�������������׾Ͳ��÷Ż����ˡ�\n\n"
	]));

	set("jian_count", 20);            
	set("dao_count", 20);   
	set("bang_count", 20);      
	set("gun_count", 20);
	set("zhang_count", 20);
	set("chui_count", 20);           
	set("bian_count", 20); 
	set("ling_count", 20);
	set("armor_count", 20);

	setup();
}

void init()
{
        add_action("do_get","na");
        add_action("do_put","fang");
}

int do_get(string arg)
{
        object me,ob;
        string arg1;
        me=this_player();

        if(!arg) return notify_fail("�����ʽ: na <��������> \n");
        switch (arg){
		case "jian": arg1="/clone/weapon/changjian"; break;             
		case "dao": arg1="/clone/weapon/blade"; break;   
		case "bian": arg1="/clone/weapon/whip"; break;         
		case "zhang": arg1="/clone/weapon/gangzhang"; break;
		case "gun": arg1="/clone/weapon/tiegun"; break;           
		case "chui": arg1="/clone/weapon/tiechui"; break;
		case "bang": arg1="/clone/weapon/zhubang"; break; 
		case "ling":arg1="/clone/weapon/tieling";break;
		case "armor":arg1="/clone/armor/armor";break;
		default : return notify_fail("û�����ֱ�����\n");
        }
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
        if(query(arg+"_count") < 1)
                return notify_fail("���ֱ����Ѿ����ù��ˡ�\n");
        if(me->query_temp("bingqi/get")>3)
                return notify_fail("���Ѿ��ù��ü��������ˣ�Ϊ������������ɡ�\n");
        add(arg+"_count", -1);
        ob=new(arg1);
        if(ob) ob->move(me);
        ob->set("value", 10);
        if(!me->query_temp("bingqi/get")) 
        me->set_temp("bingqi/get",1);
        else me->add_temp("bingqi/get",1);
        message_vision("$N�ӱ��������ó�һ"+ob->query("unit")+"$n��\n",me, ob);  
        return 1;
}

int do_put(string arg)
{
        object me, ob;
        string arg1;
        me=this_player();
        if (!arg) return 0;
        if (me->is_busy()) return notify_fail("����æ���ء�\n");
        if( !objectp(ob = present(arg, me)) )
                return notify_fail("������û������������\n");
        if(!ob->query("weapon_prop")) 
                return notify_fail("��ֻ�ܽ��������ڱ������ϡ�\n");
        if (me->is_busy())
                return notify_fail("����æ���ء�\n");
        arg1=ob->query("skill_type");
        switch (arg1){
                case "sword": add("jian_count", 1); break;             
                case "blade": add("dao_count", 1); break;   
                case "stick": add("bang_count", 1); break;         
                case "club": add("gun_count", 1); break;
                case "stuff": add("zhang_count", 1); break;
                case "hammer": add("chui_count", 1); break;           
                case "whip": add("bian_count", 1); break;
                case "ling": add("ling_count", 2); break;
                case "armor": add("armor_count", 1); break;
                default :
                        return notify_fail("�㲻�ܽ����ֱ������ڱ������ϡ�\n");
        }
        message_vision("$N�ó�һ"+ob->query("unit")+"$n���ڱ������ϡ�\n",me, ob);  
        me->add_temp("bingqi/get",-1);
        destruct(ob);
        return 1;
}
