//Cracked by Kafei
// Carriage: /clone/obj/carm.c
// xbc: 04/15/1997

#include <ansi.h>
inherit ITEM;

void arrive(object, object, object, object, string, string, string);
int do_zuo(string arg);

void create()
{
        set_name(RED "��" NOR, ({ "da che", "che", "carriage"}) );
	set_weight(500000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
	else {
		set("unit", "��");
        	set("long", @LONG
����һ������ƥ�����ŵĴ�������ǰ������һ��������ϳ���

��������˿������͸��˵�˵�����Ǹϴ󳵴��»��ȥ���ݣ����ݣ�Ȫ�ݣ�
��ɽ��̩ɽ�����֣����������ڣ��䵱�����ң��������ģ���ɽ�����ޣ�
ѩɽ�����ݵȵ����εġ�

LONG
	);
		set("value", 1000000);
		set("material", "steel");
		set("no_get",1);
	}
	setup();
}

void init()
{
//	add_action("do_zuo", "zuo");
//	add_action("do_zuo", "cheng");
	add_action("do_travel", "travel");
}

/*
int do_zuo(string arg)
{
	object me = this_player();
	object money = present("gold", me);

    	if( !arg || arg=="" ) return 0;

    	if( arg=="da che" || arg=="carriage" || arg=="che" || arg=="��") arg = "��";

	message_vision(CYN "$N�Գ���˵����λ���壬����Ҫ��" + arg + "��\n" NOR, me);

    	if( arg=="��") {

		if ( !me->query_temp("marriage/newly_wed")) {
               		message_vision(CYN "����˵���������������˼�������������ȥ���еģ�\n" +
				"����ҡͷ������˵���ͱ�������������˰ɡ�\n" NOR, me);
			return 1;
		}

      		message_vision(CYN "����˵�����������Ҿ����˼�����������ȥ���εģ�\n" +
			"������˵�˵����˵�ɣ�ȥ���\n" NOR, me);

        	return 1;
	}

    	else
        	message_vision(CYN "�����ɻ������$N���ţ� " + arg + "��\n" NOR, me);
    	return 1;
}
*/

int do_travel(string arg)
{
        object ob = this_object();
        object me = this_player();
        object spouse;

	object ob2; 
	string destin, destch, destmg;

	if ( !me->query_temp("marriage/newly_wed")) {
      		message_vision(CYN "����˵���������������˼�������������ȥ���еģ�\n" +
			"����ҡͷ������˵���ͱ�������������˰ɡ�\n" NOR, me);
		return 1;
	}
        if( !(spouse = present(me->query("spouse/id"), environment(me)))) {
                message_vision(CYN "����Ц���еض�$N˵����ô������λ���ˣ�������һ��ȥ� \n" NOR, me);
                return 1;
        }

	if ( !arg ) 
		return notify_fail(CYN "�����ɻ���ʣ�ȥ���\n" NOR);

	if ( arg == "wudang" || arg == "�䵱" ) {
		destin = "/d/wudang/shanmen";
		destch = "�䵱";
		destmg = "��������������ɽ�������䵱���ӵ�Ҫȥ��������ϵ�����";
	}
	else if ( arg == "shaolin" || arg == "����" ) {
		destin = "/d/shaolin/shanmen";
		destch = "����";
		destmg = "��������ɽ�ţ�Ů�Ͳ��������ˣ�����Ϳ���ȥ�㳡����������ֻ�����ֵ��ӺͿ����ǲ��С�";
	}
	else if ( arg == "yangzhou" || arg == "����" ) {
		destin = "/d/city/kedian";
		destch = "����";
		destmg = "�������ݿ͵ꡣ�����˶��¶��࣬������ĵط�Ҳ�����š�";
	}
	else if ( arg == "xingxiu" || arg == "����" ) {
		destin = "/d/xingxiu/xxh2";
		destch = "���޺�";
		destmg = "�����޺�����ϡ�٣����������и�С�򡣿����������ߣ�С����������������޵��ӣ������ߵ�ɳĮ������·��";
	}
	else if ( arg == "shenlong" || arg == "����" ) {
		destin = "/d/shenlong/tanggu";
		destch = "������";
		destmg = "С��ֻ������������ˡ�Ҫȥ�������������Լ��д���������Ҫ��ȥ����ǧ��С�ģ�С�����������һ�����";
	}
	else if ( arg == "quanzhou" || arg == "Ȫ��" ) {
		destin = "/d/quanzhou/zhongxin";
		destch = "Ȫ��";
		destmg = "����Ȫ�����ģ������м������ۡ���������������߼���������Ȫ������ˡ�";
	}
	else if ( arg == "huashan" || arg == "��ɽ" ) {
		destin = "/d/huashan/yunu";
		destch = "��ɽ";
		destmg = "��ɽ�ɾ����ϱߡ�ɽ�Ϸ羰������ȥתת�������������һ�����";
	}
	else if ( arg == "taishan" || arg == "̩ɽ" ) {
		destin = "/d/taishan/wudafu";
		destch = "̩ɽ";
		destmg = "�����ҵ����ϲ�ȥ�������Լ�ȥ�ɡ���ɽС�ı�ˤ�š�ɽ���е����������������Ʒ���ʹ�ߡ�";
	}
	else if ( arg == "emei" || arg == "����" ) {
		destin = "/d/emei/baoguomen";
		destch = "����ɽ";
		destmg = "���Ƕ���ɽ������ɽ̫�������ϲ�ȥ���ſ��и�С������ͼ��������ɽ�������ˣ������ŵ����";
	}
	else if ( arg == "xueshan" || arg == "ѩɽ" ) {
		destin = "/d/xueshan/shanmen";
		destch = "��ѩɽ";
		destmg = "ѩɽ�ɾ����⸽�����������ߣ�С������ѩ����";
	}
	else if ( arg == "dali" || arg == "����" ) {
		destin = "/d/dali/wangfu1";
		destch = "�����"; 
		destmg = "����Ǵ���������������ˡ��������Ǹ�ԣ�ĺõط���ʲô�������С���������ɡ�";
	}
	else if ( arg == "xixia" || arg == "����" ) {
		destin = "/d/xixia/oldwall";
		destch = "���Ĺ�";
		destmg = "С�Ĳ������������ˣ�ȥ���Ĺ������Լ��д��ɡ�С�����������һ���ӡ�";
	}
	else if ( arg == "hangzhou" || arg == "����" ) {
		destin = "/d/hangzhou/kedian";
		destch = "����";
		destmg = "���ݵķ羰��������һ���ģ���������ת�ɡ�";
        }
	else if ( arg == "lanzhou" || arg == "����" ) {
		destin = "/d/qilian/lanzhou";
		destch = "����";
		destmg = "���ݿ��к�Щ�õط����ط���С�����Ǳ��߶��ˡ�";
	}
        else if ( arg == "foshan" || arg == "��ɽ" ) {
                 destin = "/d/foshan/ngate";
                 destch = "��ɽ";
                 destmg = "��ɽ��·�����¿��ġ����ﱱ���䵱������Ȫ�ݣ���ͨ������ͨ��������������ɡ�";
	}
	else return notify_fail(CYN "���򲻺���˼��˵������С�Ĳ���Ϥ�Ǳߵ�·����֪����ôȥ��\n" NOR);

	message_vision(HIC "$N��$n�����󳵣�$N�Գ���˵�˼��仰��\n�����������бޣ�ߺ���ţ�������������ȥ"+destch+"ඣ�\n" NOR, me, spouse);
  	tell_room(environment(me),"����������������Խ��ԽԶ������һ����Ͳ����ˡ�\n\n", me);

	ob2 = new(__DIR__"carm2.c");

	me->move(ob2);
	spouse->move(ob2);

	ob->move(__DIR__"car3");
	tell_room(environment(me), "�������������Ȼ��֪������龰�����λ����ƣ�ͣͣ���ߣ���֪���˶����졭��\n\n");

	me->start_call_out( (:call_other, __FILE__, "arrive", me, spouse, ob2, ob, destin, destch, destmg :), 60);

	return 1;
}

void arrive(object me, object spouse, object ob2, object ob, string destin, string destch, string destmg)
{
	ob->move(destin);
	me->move(destin);
	spouse->move(destin);

        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob2);

	tell_room(environment(me),"��ƥ������һ�˴����˹���������һ��ߺ�ȣ���ͣ��������\n");

        message_vision("�������˵�����������������"+destch+"�����漴�ƿ����š�\n" + RED + "$N��$nЯ�ִӳ�������������\n" NOR, me, spouse );
        message_vision("������˵����"+destmg+"��\n", me );
        message_vision("���򽫴󳵸ϵ�һ�ԣ���ʼ�������\n\n", me );

}

void destroy_it(object obj)
{
        destruct(obj);
}

