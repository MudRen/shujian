// ITEM: /d/huashan/npc/obj/ling.c
// Date: Look 99/03/25
// ��������Ŷ���޷�͵ȡBy server@sjty

inherit ITEM;

#include <ansi.h>
void create()
{
        set_name(YEL"����"NOR, ({ "ling pai","ling"}));
        set_weight(10);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һö��ɽ�ɵ����Ʒ��������������ɽ�����������ʱ�������Լ����Ʒ���\n");
                set("value", 0);
                set("material", "iron");
                set("no_steal", 1);
         }
	setup();
}
int move(mixed dest, int silently)
{
	int i;
		
	i = ::move(dest, silently);
	if(i && stringp(this_object()->query("ever_owner"))){
		this_object()->set("owner",this_object()->query("ever_owner"));
		remove_call_out("delete_owner");
		call_out("delete_owner",90+random(30));
	}
	return i;
}
