// /clone/armor/longpao.c ����

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"����"NOR, ({ "longpao", "long pao", "pao" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIY"����һ���ֹ���ϸ�ޱȵĵ����ۣ�������������ʯ��觵Ⱦ����䱦������
����е�Х��������ë֯�ɣ���˸�������Ĺ�ʣ��������롣����Ľ����
���洫���֮������˵Ľ������Ϊ�˶���ʮ��֮�����Ѽ����Ƴɡ�\n"NOR);
                set("material", "silk");
                set("unit", "��");
                set("unique", 1);
                set("value", 1000000);
                set("wear_msg", HIY "ֻ��$N����һ�����ۣ����ׯ�ϣ�ʹ�˲������ӡ�\n" NOR);
                set("remove_msg", HIR "$N����һ����"HIY"�� ��"HIR"�������������ˣ�С������ķ���������\n" NOR);
                set("treasure",1);
                set("armor_prop/armor", 50);
        }
        setup();
}
