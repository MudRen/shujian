// dujiaotongren.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name( "����ͭ��" , ({ "dujiao tongren", "dujiao", "tongren" }));
        set_weight(30000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ұ����������һ���������Σ�����һ�۸߾٣���������һֻ�ʡ���Ȼ����Ҳ����������Ѩ��\n");
                set("value", 1000);
                set("material", "bronze");
                set("wield_msg", "$N����һ��������˫������һ������ͭ�ˡ�\n");
                set("unwield_msg"," $N�Ѷ���ͭ�˰�Ľ��ʵʵ���ڱ���\n");
        }
        init_staff(40);
        setup();
}
