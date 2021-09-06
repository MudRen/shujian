//Cracked by Kafei
// Carriage: /clone/obj/car.c
// xbc: 04/15/1997
// modified by aln 4 / 98
// added check for hs dizi, sdong 07/24/98
// added check busy by maco 2/19/2000

#include <ansi.h>
inherit ITEM;

void arrive(object, object, object, string, string, string);
int do_hire(string arg);

void create()
{
	set_name("��", ({ "da che", "che", "carriage"}) );
	set_weight(10000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", @LONG
����һ������ƥ�����ŵĴ󳵡���ǰ������һ���ϳ�����������ֻ���ޡ�
�����ﲻͣ�źߺ���ʲô���Ĳ����ɵ��������š�

��������˿��������������˵���ʹ��𣿰�����ȥ���ݣ����ݣ�Ȫ�ݣ�
̩ɽ�����֣����������ڣ��䵱�����ң��������ģ���ɽ�����ޣ�ѩɽ��
���ݣ���ɽ������ɽ����

LONG
	);
		set("value", 1000000);
		set("material", "steel");
		set("no_get",1);
		set("no_clean_up", 1);
	}
	setup();
}

void init()
{
	add_action("do_hire", "hire");
	add_action("do_hire", "gu");
	add_action("do_travel", "qu");
}

int do_hire(string arg)
{
	object me = this_player();

	if( !arg || arg== "" ) return 0;

	if( !(arg == "da che" || arg == "carriage" || arg == "che" || arg == "��") ) {
		message_vision("�����ɻ������$N���ţ� " + arg + "��\n", me);
		return 1;
	}

	message_vision("$N�Գ���˵����λ���壬����Ҫ�ʹ󳵣�\n", me);

	if( me->query("mud_age") < 24000 && me->query("combat_exp") < 200 ) {
		message_vision("������$N����һ�����˵�����������ҿ������������˵صİɣ�\n" +
		"�����$N����һ��˵���˼��и��������˵��Ҫ�����ѣ����԰��������󳵸�����һ���¡�\n" +
		"����ͦ��ͦ��������������˵�ɣ�ȥ���\n", me);
		me->set_temp("paid", 1);
		return 1;
	}

// modified by qfy: to prevent huashan dizi who are currently doing job to leave huashan.
	if( me->query_condition("hz_job") ) {
		message_vision("��������������Ц��$N˵�����͹��ţ���Բ���С�Ľ������һ���쳵��������������\n" +
		"������ЪһЪ�ţ�������������\n", me);
		return 1;
	}

	if( me->query_temp("paid") ) {
		message_vision("�����$N˵���͹��ţ����ղŸ���Ǯ������һ�����ء���˵Ҫȥ����ɣ�\n", me);
		return 1;
	}
			
	switch (MONEY_D->player_pay(this_player(), 1000)) {
	case 0:
		write("��⵰��һ�ߴ���ȥ��\n");
		return 1;
	case 2:
		write("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
		return 1;
	default:
		break;
	}

	message_vision("$N�ͳ�ʮ�����Ӹ����򡣳�������������˵࣬���˵�����������\n", me);
	message_vision("����ض�$N���ͷ˵����л���ϣ�����Ҫ�ͳ�ȥ���\n", me);
	me->add_temp("paid", 2);
	return 1;
}

int do_travel(string arg)
{
	object ob = this_object();
	object me = this_player();
	object ob1, ob2; 
	string destin, destch, destmg;

	if( !arg ) {
		write("�����ɻ���ʣ�ȥ���\n");
		return 1;
	}

	if( me->query_condition("hz_job") ) {
		write("��������Ц����������Ⱥ�����������������Ѳɽ�ĵ��ӳ�ɽ��\n��λ" + RANK_D->query_respect(me) +
		"��ʵ���ǶԲ�������\n");
		return 1;
	} // added by sdong


	if( !me->query_temp("paid") ) {
		if ( me->query("mud_age") < 24000 && me->query("combat_exp") < 200 ) {
		message_vision("������$N����һ�����˵�����������ҿ������������˵صİɣ�\n" +
	       "�����$N����һ��˵���˼��и��������˵��Ҫ�����ѣ����԰��������󳵸�����һ���¡�\n", me);
		me->set_temp("paid", 1);
		} else {
		write("�������µ���ι����λ" + RANK_D->query_respect(me) +
		"����Ǯ����������󳵰���\n" +
		"����ٺ�һЦ���ҿ��������Լ���·�ɣ�\n");
		return 1;
		}
       
	}

	if( me->is_busy() ) {
		write("����˵������" + RANK_D->query_respect(me) + "��æ���ˣ�С��������·��\n");
		return 1;
	}

	if( arg == "wudang" || arg == "�䵱" ) {
		destin = "/d/wudang/shanmen";
		destch = "�䵱";
		destmg = "��������������ɽ�������䵱���ӵ�Ҫȥ��������ϵ�����";
	} else if( arg == "shaolin" || arg == "����" ) {
		destin = "/d/shaolin/shanmen";
		destch = "����";
		destmg = "��������ɽ�ţ�Ů�Ͳ��������ˣ�����Ϳ���ȥ�㳡����������ֻ�����ֵ��ӺͿ����ǲ��С�";
	} else if( arg == "yangzhou" || arg == "����" ) {
		destin = "/d/city/kedian";
		destch = "����";
		destmg = "�������ݿ͵ꡣ�����˶��¶��࣬������ĵط�Ҳ�����š�";
	} else if( arg == "xingxiu" || arg == "����" ) {
		destin = "/d/xingxiu/xxh2";
		destch = "���޺�";
		destmg = "�����޺�����ϡ�٣����������и�С�򡣿����������ߣ�С����������������޵��ӣ������ߵ�ɳĮ������·��";
	} else if( arg == "shenlong" || arg == "����" || arg == "����" ) {
		destin = "/d/beijing/tanggu";
		destch = "������";
		destmg = "С��ֻ������������ˡ�Ҫȥ�������������Լ��д���������Ҫ��ȥ����ǧ��С�ģ�С�����������һ�����";
	} else if( arg == "quanzhou" || arg == "Ȫ��" ) {
		destin = "/d/quanzhou/zhongxin";
		destch = "Ȫ��";
		destmg = "����Ȫ�����ģ������м������ۡ���������������߼���������Ȫ������ˡ�";
	} else if( arg == "huashan" || arg == "��ɽ" ) {
		destin = "/d/huashan/yunu";
		destch = "��ɽ";
		destmg = "��ɽ�ɾ����ϱߡ�ɽ�Ϸ羰������ȥתת�������������һ�����";
	} else if( arg == "taishan" || arg == "̩ɽ" ) {
		destin = "/d/taishan/wudafu";
		destch = "̩ɽ";
		destmg = "�����ҵ����ϲ�ȥ�������Լ�ȥ�ɡ���ɽС�ı�ˤ�š�ɽ���е����������������Ʒ���ʹ�ߡ�";
	} else if( arg == "emei" || arg == "����" ) {
		destin = "/d/emei/baoguomen";
		destch = "����ɽ";
		destmg = "���Ƕ���ɽ������ɽ̫�������ϲ�ȥ���ſ��и�С������ͼ��������ɽ�������ˣ������ŵ����";
	} else if( arg == "xueshan" || arg == "ѩɽ" ) {
		destin = "/d/xueshan/shanmen";
		destch = "��ѩɽ";
		destmg = "ѩɽ�ɾ����⸽�����������ߣ�С������ѩ����";
	} else if( arg == "dali" || arg == "����" ) {
		destin = "/d/dali/wangfu1";
		destch = "�����"; 
		destmg = "����Ǵ���������������ˡ��������Ǹ�ԣ�ĺõط���ʲô�������С���������ɡ�";
	} else if( arg == "xixia" || arg == "����" ) {
		destin = "/d/xixia/oldwall";
		destch = "���Ĺ�";
		destmg = "С�Ĳ������������ˣ�ȥ���Ĺ������Լ��д��ɡ�С�����������һ���ӡ�";
	} else if( arg == "hangzhou" || arg == "����" ) {
		destin = "/d/hangzhou/kedian";
		destch = "����";
		destmg = "���ݵķ羰��������һ���ģ����Լ�����ת�ɡ�";
	} else if( arg == "lanzhou" || arg == "����" ) {
		destin = "/d/qilian/lanzhou";
		destch = "����";
		destmg = "���ݿ��к�Щ�õط����ط���С����С�ı�ת���ˡ�";
	} else if( arg == "foshan" || arg == "��ɽ" ) {
		destin = "/d/foshan/ngate";
		destch = "��ɽ";
		destmg = "��ɽ��·�����¿��ġ����ﱱ���䵱������Ȫ�ݣ���ͨ������ͨ��������������ɡ�";
	} else if( arg == "zhongnanshan" || arg == "zhongnan" || arg == "����ɽ" ) {
		destin = "/d/zhongnan/shenheyuan";
		destch = "����ɽ";
		destmg = "����ɽ����ȫ��̵Ĵ�Ӫ��ȫ���书��������ѧ���ڡ����ﻹ��һ����Ĺ��һ�����ǲ��ÿ����ģ���˵�����л��ء�����ɽ�ɴ����أ���������ɡ�";
	} else if( arg == "dongbei" || arg == "����" || arg == "changbai" || arg == "����ɽ" ) {
		destin = "/d/changbai/jishi";
		destch = "����";
		destmg = "����Ǻ�ͼ�����ǣ�����ȥ���ǳ���ɽ�ˣ�һ·�϶��Ǳ���ѩ�أ���·ǰ��ô�ЩƤë��װ��С�Ĳ���������ȥ�ˡ�";
	} else {
		write("���򲻺���˼��˵������С�Ĳ���Ϥ�Ǳߵ�·����֪����ôȥ��\n");
		return 1;
	}

	message_vision("$N�����󳵣��Գ���˵�˼��仰��\n�����������бޣ�ߺ���ţ�������������ȥ"+destch+"ඣ�\n\n", me);
	tell_room(environment(me), "����������������Խ��ԽԶ������һ����Ͳ����ˡ�\n\n", me);

	ob2 = new(__DIR__"car2.c");
	me->move(ob2);

	if( !objectp(ob1 = find_object(__DIR__"car3")) ) 
		ob1 = load_object(__DIR__"car3");
	ob->move(ob1);
	tell_object(me, "�����������Ȼ��֪������龰�����λ����ƣ�ͣͣ���ߣ���֪���˶����졭��\n\n");

	me->start_busy(16); // set the busy time to the same as arrive time, otherwise player
						// may quit in da che and cannot arrive at dest.. sdong
	me->add_temp("paid", -1);

	remove_call_out("arrive");
	call_out("arrive", 30, me, ob2, ob, destin, destch, destmg);

	return 1;
}

void arrive(object me, object ob2, object ob, string destin, string destch, string destmg) 
{
    if( ob ) ob->move(destin);
	if( me ) me->move(destin);

	remove_call_out("destroy_it");
	call_out("destroy_it", 1, ob2);

	tell_room(environment(me),"��ƥ������һ�˴����˹���������һ��ߺ�ȣ���ͣ��������\n");

	message_vision("�������˵�����������������"+destch+"�����漴�ƿ����š�\n$N�ӳ�������������\n", me );
	message_vision(CYN "������˵����"+destmg+"��\n" NOR, me );
	message_vision("���򽫴󳵸ϵ�һ�ԣ���ʼ�������\n\n", me );
}

void destroy_it(object obj)
{
	destruct(obj);
}
