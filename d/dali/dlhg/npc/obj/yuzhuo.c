#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
        set_name(HIW"������"NOR,({ "yu zhuozi", "zhuozi" }));
        set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "\n����һ�����������\n");
		set("value", 500000); 
                set("unique", 1);
                set("treasure", 1);
                set("unequip_msg", "$Nժ�����ϵ�$n��\n");
                set("armor_prop/armor", 1);
	}
	setup();
}

int wear()
{
        object me = environment();
	int ret;
        message_vision("$N��һ��" + this_object()->query("name") + "���������ϡ�", me);
        if (ret=::wear()) {
                if (me->query("gender") == "����")
                        message_vision("���˼�ҲҪ����������Ц�����ˡ�\n", me);
                else if (me->query("gender") == "Ů��")
                        message_vision("�����⸶����$N�Եø���������\n", me);
                else
                        message_vision("$N����Խ���붫�������ˡ�\n", me);
        }
        return ret;
}
