// user_armor.c ���Ʒ���
// create by snowman@sj
// modify by augx@sj   10/11/2001
// Modified by Ciwei@SJ

#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void save_armor(object me);
void delete_armor(object me);

void create()
{
	set_name("��ͨ����", ({ "user armor" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "cloth");
		set("wield_maxneili", 100000);
		set("wield_dex", 20);
		set("wield_str", 20);
		set("imbued", 1);
	}
	set("armor_prop/armor", 1);
	set("armor_type", TYPE_CLOTH);
	//setup();
}

int armor_setup(mapping mp)
{
	string *vb;
	int i;

	if( !clonep(this_object()) ) return 0;
	if( !mapp(mp) ) return 0;

	vb = keys(mp);

	for( i = 0; i < sizeof(vb); i++ )
		set(vb[i], mp[vb[i]]);

	set_name(mp["name"], mp["id"]);
	set_weight(mp["weight"]);
	return 1;
}

int move(mixed dest, int silently)
{
	object src = environment();
	int result, i=0, j;

	if( (result = ::move(dest, silently)) ) {
		if (src && userp(src)) { delete_armor(src); i=1; }
		if (dest && userp(dest)) { save_armor(dest); i=1; }
		if (i) {
			if(src)  set("move/src",src->query("id"));   else set("move/src","");
			if(dest) set("move/dest",dest->query("id")); else set("move/dest","");
			set("move/time",time());
		}
		if (!i || !WORKER_D->check_item(this_object(), src, dest)) {
			i = query("imbued");
			if (i>=3 && dest && userp(dest)
			&& sscanf(query("save_id"),dest->query("id")+"%*d") != 1
			&& query("wear_maxneili")*7/10 > dest->query("max_neili")
			&& ((j = dest->query_skill("caijian",1)) < 170 && i == 3
			 || i == 4 && j < 270
			 || i == 5 && j < 390))
				call_out("cant_keep",1,dest);
		}
	}

	return result;
}

void cant_keep(object me)
{
	if( !me || !userp(me) || environment()!=me || !environment(me) ) return;

	message_vision("����$N�����ò�ס��" + name() + "����������\n", me);
        if(!(this_object()->move(environment(me))) ) {
		message_vision("һ���Ӿ�ʧȥ����Ӱ��\n",me);
		destruct(this_object());
	}
}

void save_armor(object me)
{
	mapping mp;
	object wp = this_object();

	mp = wp->query("armor_mp");
	if ( !mapp(mp) || !mapp(wp->query("armor_prop")) ) return;	
	if(stringp(query("owner"))
	&& query("owner")!="0"
	&& query("owner")!=getuid(me)) return;
	
	mp["user"] = query("user");
	mp["ltime"] = query("ltime");
	me->set("worker/"+mp["save_id"], copy( WORKER_D->convert_armor2user(mp) ));
	if(userp(me)) me->save();
}

void delete_armor(object me)
{
	if(stringp(query("owner")) && query("owner")==getuid(me)) return;
	me->delete( "worker/" + query("armor_mp/save_id") );
}

void delete_weapon2(object me)
{
	me->delete( "worker/" + query("armor_mp/save_id") );
	if(stringp(query("owner")) && query("owner")!="" && query("owner")!="0" && query("owner")!=getuid(me))
		WORKER_D->deleteweapon(query("owner"),"���"+name()+"��Ϊ��"+me->name()+"�𻵶����Զ�ɾ�����Ѿ����������˽��������\n",query("armor_mp/save_id") );
}

void remove(string euid)
{
	object ob = environment(this_object());

	if(!clonep(this_object())) {
		::remove(euid);
		return;
	}

	if ( !(int)query_temp("quit_dest") ) {
		if( ob && userp(ob) ) delete_armor(ob);
		//if( query("armor_mp/imbued") > 3 )
			//WORKER_D->addto_pool("delete",query("armor_mp/save_id")," ");

		if( query("armor_mp/imbued") > 2 ) {
			// save_id : time : src : dest : user : euid
			log_file("career/delete", sprintf("%-19s:%d:%s:%s:%s:%s\n",
				query("armor_mp/save_id"),
				query("move/time"),
				(string)query("move/src"),
				(string)query("move/dest"),
				objectp(ob)?ob->query("id"):"",
				euid
				), ob);
		}
	}
	else {
		if( ob && userp(ob) ) save_armor(ob);
		//if( query("armor_mp/imbued") > 3 )
			//WORKER_D->addto_pool("update",query("armor_mp/save_id"),sprintf("%d",time()));
	}

	::remove(euid);
}

void init()
{
	add_action("do_xuli","xuli");
}

void showneili()
{
	string xuli;

	if( query("neili") )
		xuli = "�����Ѿ�������" + CHINESE_D->chinese_number( (query("neili")+999)/1000 ) + "��������\n";
	else
		xuli = "";
	if( stringp(query("xuli")) && strlen(query("xuli"))>3 )  {
		if( xuli != query("xuli") )
			set("long", replace_string(query("long"),query("xuli"),xuli) );
	}
	else
		set("long", query("long") + xuli);
	set("xuli", xuli);
}

int do_xuli(string arg)
{
	object me = this_player();

	if( (int)query("storeneili") <= 0 ) return 0;

	if( me->query_skill("force") < 100 )
		return notify_fail("����ڹ��ȼ��������޷�������\n");
	if( (int)query("neili") >= query("storeneili") )
		return notify_fail(name()+"���Ѿ�����������������Ҳ�޷�ע���ˣ�\n");
	if( me->query("neili") < 1000 )
		return notify_fail("����������㣬�޷�ע���㹻��������\n");

	if (query("last_xuli") && query("last_xuli")!=me->query("id")) {
		set("neili" , query("neili")/2);
		message_vision(MAG"$N�����Լ���������"+name()+MAG"��ԭ�е��������ͻ����Ȼ���ջ���ע����$N�����������Ѿ���ʧ�˲��١�\n",me);
	}
	set("last_xuli", me->query("id"));

	add("neili", 1000);
	if (query("neili") > query("storeneili")) set("neili", query("storeneili"));
	me->add("neili", -1000);

	showneili();
	message_vision(MAG"$NǱ��������˫���鰴"+name()+MAG"��������ע��"+name()+MAG"֮�С�\n"NOR,me);
	return 1;
}

mixed ob_hit()
{
	int times,qi,cost;
	object target;
	object me;
	int damage;

	if( (int)query("storeneili") && (int)query("neili") && damage>250 ) {
		times = query("storetimes");
		if (query("last_xuli") != me->query("id")) times = times * 3/2;
		cost = (damage/2) * times/100;
		qi = damage/2;
		if( cost > query("neili") ) {
			qi = qi * query("neili") / cost ;
			cost = query("neili");
		}
		add("neili" , -cost);
		if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("q:%d , n:%d  ",qi,cost));
		message_vision(MAG+name()+MAG"����һ�������Ĺ�â���ֵ���$N�Ĳ��ֹ��ƣ�\n"NOR,target);
		showneili();
		return -qi;
	}

	if( (int)query("decdamage") && damage>200 ) {
		qi = damage * random(query("decdamage")) / 100;
		if(qi<10) qi=10;
		if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("d:%d , q:%d  ",damage,qi));
		message_vision(HIY"$N����ʽ��$n��"+name()+HIY"�ϣ��ƺ������޻��ʹ����������\n"NOR,target,me);
		return -qi;
	}

	return 0;
}
/*��һ��ʱ���ڣ����˲���get Kill NPC����ڵ��ϵı�����*/
void delete_owner()
{
   if (query("tmp_owner"))
    {
    remove_call_out("delete_tmpowner");
		call_out("delete_tmpowner",50);
		}
}

void delete_tmpowner()
{
	if (!this_object()) return;
	if (!query("tmp_owner")) return;
	
	delete("tmp_owner");
	return;
}