// OBJ : /d/wudang/obj/lingxian.c ����

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(MAG"����"NOR, ({"yao cai","ling xian","yao"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
            set("unit", "��");
            set("long", YEL"����һ��մ�ɽ���в�ժ������ҩ�ģ������Ŵ�����������Ϣ��\n"NOR);
            set("value", 100);
        }
        setup();
}

