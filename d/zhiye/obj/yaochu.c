// yaochu.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void set_status(int i);
int query_status();

void create()
{
	set_name("ҩ��", ({ "yao chu", "yaochu" }));
	set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��ҩ����\n");
		set("olong", "����һ��ҩ��������������ҩ(caiyao)��\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", "$N����һ��$n��\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
		set("worker_tool",1);
	}
	set("used",70);
	set("oused",70);
	init_staff(20);
	set_status(70);
	set("worker",1);
	set("stime",time());
	setup();
}

void set_status(int i)
{
	int j;
	j = (int)(i*100/query("oused"));
	if(j>90) set("long",query("olong")+"������������õġ�\n");
	else if(j>50) set("long",query("olong")+"�������Ѿ��ù�һ��ʱ���ˡ�\n");
	else if(j>20) set("long",query("olong")+"�������Ѿ���Щ�����ˡ�\n");
	else if(j>0) set("long",query("olong")+"��������Ҫ���ˡ�\n");
	else set("long",query("olong")+"�������Ѿ������ˡ�\n");
	set("used",i);
}

int query_status()
{
	return query("used");
}

void use()
{
	object me = environment(this_object());
	if( query_status()<=0 ) return;
	if( query_status()>2 && (time()-query("stime"))>7200 ) {
		tell_object(me,"���"+query("name")+"�ƺ���Щ�����ˣ�\n");
		set_status(2);
	}
	set_status(query_status()-1);
	if( query_status()<=0 ) {
		if( objectp(me) && userp(me) )
			tell_object(me,"���"+query("name")+"�����ˣ�\n");
		broken("������");
	}
}
