
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(WHT "�׻��ų���" NOR, ({ "baihu chengmen", "chengmen"}) );         
        set_weight(30000000);
        
        set("unit", "��");
set("long", @LONG
����һ�Ժ��صĳ��ţ������عر��ţ�����¥����һ�Ӷ���װ��ʿ��
������ȥ���������������ս������������ʧ��������˴�Ƭ�Ļ�
�أ�����ϡ�١�
LONG);
set("value",50000000); 
set("no_get",1);
set("defend",15); // ���
        setup();
}

void init()
{
	
object me = this_player();
	
	
	if (this_object()->query("defend") <= 0)
 {
message_vision(RED""+this_object()->query("name")+RED"��Ҳ���ܲ�ס���������һ�����ˡ�\n"NOR, me);
	}
}
