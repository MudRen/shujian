
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL "����" NOR, ({ "cheng men", "men" ,"door"}) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
set("long", @LONG
����һ�Ժ��صĳ��ţ������عر��ţ�����¥����һ�Ӷ���װ��ʿ��
������ȥ���������������ս������������ʧ��������˴�Ƭ�Ļ�
�أ�����ϡ�١�
LONG);
set("value",50000000); 
set("no_get",1);
        setup();
}
}
