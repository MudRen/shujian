// emeici.c

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
       set_name(WHT"��ˮ���Ҵ�"NOR, ({ "emei ci","sword","ci","needle" }));
       set_weight(2000);
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("unit", "��");
               set("long", "����һ�����쾫�µķ�ˮ���Ҵ̡�\n");
               set("value", 2000);
               set("material", "steel");
               set("wield_msg", "$N�ӻ����ͳ�һ��$n��\n");
               set("unwield_msg", "$N�����е�$n���뻳�С�\n");
       }
       init_dagger(30);
       setup();
}

