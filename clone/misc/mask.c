// mask.c yujue

#include <armor.h>
inherit HEAD;

void create()
{
	set_name("����", ({ "mian zhao", "zhao", "mask" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("wear_msg", "$Nȡ��һ����������ͷ�ϡ�\n");
		set("remove_msg", "$N����������������\n");
		set("no_drop", 1);
		set("unique", 3);
        }
        setup();
}

int wear()
{
	object ob = environment();
	string id;
	int ret;

	if (!living(ob)) {
		message_vision("���ִ�$Nͷ�ϵ���������\n", ob);
		return 0;
	}

	if (ret=::wear() && userp(ob)) {
		id = ob->query("id");
		id = id[0..0]+id[<1..<1];
		ob->set_temp("apply/id", ({ id }));
		id = capitalize(id);
/*
		if (wizardp(ob)) {
			ob->set_temp("apply/name", ({ "������ʦ" }));
			ob->set_temp("apply/short", ({ "������ʦ(Mengmian wushi)" }));
		} else
*/
		if (ob->query("gender") == "Ů��") {
			ob->set_temp("apply/name", ({ "����Ů��" }));
			ob->set_temp("apply/short", ({ "����Ů��("+id+")" }));
		} else {
			ob->set_temp("apply/name", ({ "��������" }));
			ob->set_temp("apply/short", ({ "��������("+id+")" }));
		}
		ob->set_temp("apply/long", ({ "һ��Ī������ļһ���ڴ������֣��㿴�������һ����Ŀ��\n" }));
	}
	return ret;
}

int unequip()
{
	object ob = environment();
	int ret = ::unequip();

	if (ret) {
		ob->delete_temp("apply/id");
		ob->delete_temp("apply/name");
		ob->delete_temp("apply/short");
		ob->delete_temp("apply/long");
	}
	return ret;
}
