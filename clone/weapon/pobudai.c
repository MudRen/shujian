// pobudai.c �Ʋ���

#include <weapon.h>
inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name("�Ʋ���", ({ "po budai", "budai","bian" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������������鲼�����������������\n");
                set("value", 10);
                set("unique", 1);
                set("material", "cloth");
                set("rigidity", 4);
                set("weapon_prop/parry", 2);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 900);  
                set("wield_str", 22);
                set("wield_msg", "$N�ӻ����ͳ�һ���Ʋ���ץ�����е�������\n");
                set("unwield_msg", "$N�����е�$n��һ�ۣ��Ž����\n");
        }
        init_whip(40);
        setup();
}
