#include <ansi.h>
inherit ITEM;

void initlvl();

void create()
{
        set_name(HIC"���콳��ƪ"NOR,({"canpian","yitian canpian","book"}));
        set_weight(1000);     
        set("unit", "��");
        set("long","һ�����ҵ��ֲᣬ�ֿ������񻭹����
����ϸϸ���ģ������Լ���ѧ�Ĺ���֮������������һ����¼���ϳ˹���֮�����ؼ������ɵ������㵸������
\n");
        set("value", 500000);
        set("material", "paper");        
        set("for_forg",1); 
        set("credit",1500);  
      set("no_give",1);
      set("no_drop",1);   
     set("no_get",1);
        set("degree",1);
        set("flag","spec/ytbook");  
        set("desc","ѧ���¹������ܡ�");   
        setup();
        initlvl();
}

void initlvl() {
	call_out("delete_owner",90+random(30));	
}

int set_level(int i)
{
	switch (i) {
		case 1:
		set_name(HIC"���콳����ƪ"NOR,({"yitian canpian","canpian","book"}));
		set("long","һ�����ҵ��ֲᣬ�ֿ������񻭹����
����ϸϸ���ģ������Լ���ѧ�Ĺ���֮������������һ����¼���ϳ˹���֮�����ؼ������ɵ������㵸������
\n");
		break;
		case 2:
		set_name(HIM"����������ƪ"NOR,({"tulong canpian","canpian","book"}));
		set("long","һ�����ҵ��ֲᣬ�ֿ������񻭹����
����ϸϸ���ģ������Լ���ѧ�Ĺ���֮������������һ����¼���ϳ˹���֮�����ؼ������ɵ������㵸������
\n");		
		break;
		default:call_out("destroying", 1, this_object());
                 	return 0;
	}
	return 1;
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

