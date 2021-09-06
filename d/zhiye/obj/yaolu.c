// yaolu.c
// by augx@sj 2/28/2002

#include <ansi.h>
inherit ITEM;
#include "yao.h";

void create()
{
	set_name(HIY"ͭ¯"NOR, ({ "tong lu" , "lu" }));
	set_weight(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
HIR"����һ����ҹ¯��ͨ����ͭ¯���Ǹ���������Ƶ�ҩ�õġ�\n\n"NOR+
"������ô�¯��������
����(liandan)��liandan ҩ��1 and ҩ��2 and ҩ��3 ......
������ͬʱ���þ���ҩ����������
");

		set("value", 3000);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	add_action("do_liandan","liandan");
}

int need_lvl,gain_lvl,win_lvl,max_lvl,drug_lvl;

string drug_combine(object * yaocai,int n)
{
	string * id1 = ({ "zzzzz","zzzzz","zzzzz","zzzzz","zzzzz","zzzzz","zzzzz","zzzzz","zzzzz" });
	string * id2;
	string * dk;
	mapping * dv;
	int i,j,k;

	for(i=0;i<n;i++)
		id1[i] = yaocai[i]->query("id");
	id2 = sort_array(id1,1);

	dk = keys(DRUGS);
	dv = values(DRUGS);
	j = sizeof(DRUGS);
	for(i=0;i<j;i++) {
		if( n != sizeof(dv[i]["yaocai"]) ) continue;
		for(k=0;k<n;k++)
			if(id2[k]!=dv[i]["yaocai"][k]) break;
		if( k < n ) continue;

		need_lvl = dv[i]["need_lvl"];
		gain_lvl = dv[i]["gain_lvl"];
		win_lvl  = dv[i]["win_lvl"];
		max_lvl  = dv[i]["max_lvl"];
		drug_lvl = dv[i]["drug_lvl"];
		return dk[i];
	}

	need_lvl = 1;
	win_lvl = 1;
	gain_lvl = 80;
	max_lvl = 1000;
	drug_lvl = 7;
	return "null";
}

int do_liandan(string arg)
{
	object me = this_player(),tobj,weapon;
	int delay,level,i,j,yaocai_lvl,n,value,time;
	string yao,yaoname,save_id;
	string * yaocai = ({ "1","2","3","4","5","6","7","8","9" });
	object * obj = ({ 0,0,0,0,0,0,0,0,0 });

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (me->is_fight()) return notify_fail("����æ���أ�\n");
	if (!arg) return notify_fail("��Ҫ����ʲô��\n");
	arg += " and a";
	if ( (n=sscanf(arg,"%s and %s and %s and %s and %s and %s and %s and %s and %s and %s",
		yaocai[0],yaocai[1],yaocai[2],yaocai[3],yaocai[4],yaocai[5],yaocai[6],yaocai[7],yaocai[8],save_id)) < 3 )
		return notify_fail("��Ҫ��ʲôҩ�������Ƶ�ҩ����\n");
	if ( n > 9 ) n = 9;
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="yao chui" )
		return notify_fail("�����װ��ҩ��������������\n");
	if ( !weapon->query("worker_tool"))
		return notify_fail("�����װ��ҩ��������������\n");	
	if ( !wizardp(me) && (time()<(int)me->query("worker/liandan")) )
		return notify_fail("��ո������������о��������ۣ�\n");

	time = time()- me->query("pk_time");
	if ( time < 432000)
		return notify_fail("��Ŀǰ��״̬�޷�������\n");

	yaoname = "";
	yaocai_lvl = 0;
	value = 0;
	for(i=0;i<n;i++) {
		tobj = present(yaocai[i],me);
		if ( !objectp(tobj) )
			return notify_fail("������û��"+yaocai[i]+"������������\n");
		if( tobj->query("yaocai") != 1 )
			return notify_fail("���"+yaocai[i]+"�ƺ��е����⣬��������������\n");
		for(j=0;j<i;j++) {
			if( obj[j] == tobj )
				return notify_fail("һ��ҩ�������Σ�\n");
		}
		obj[i] = tobj;
		yaocai_lvl += tobj->query_level();
		value += tobj->query("value");
		yaoname += obj[i]->query("name");
		if(i<(n-1)) yaoname += "��";
	}
	yaocai_lvl /= n;

	level = (int)me->query_skill("liandan",1);
	if ( level<1 )
		return notify_fail("������Ͳ���������\n");
	if(level>390) level = 390 + (level-390)*11;

	yao = drug_combine(obj,n);
	if( level < need_lvl )
		return notify_fail("����������ܲ�����\n");

	tell_object(me,GRN"���ͭ¯�ĸ��ӣ����η�����ҩ�����õ�"+yaoname+GRN"��\n������ˮ�ٸ��ϸ��ӣ���ȼľ̿����ʼ����......\n"NOR);
	tell_room(environment(me),GRN+me->name()+GRN"��ͭ¯�ĸ��ӣ����η�����ҩ�����õ�ҩ��"+GRN"��\n������ˮ�ٸ��ϸ��ӣ���ȼľ̿����ʼ����......\n"NOR, ({me}));

	if(level>max_lvl) level = max_lvl;
	if(wizardp(me) && me->query("env/test") && win_lvl>500) win_lvl=500;

	delay = 10 + random(20);
	if( random(level+win_lvl) > win_lvl ) {
		save_id = sprintf("%s%dd",me->query("id"),time());
		if(wizardp(me) && (int)me->query("env/test")) delay = 2;
		if (drug_lvl<=2) {
			WORKER_D->update_UniqueValues("adddrug",sprintf("level=%d",drug_lvl),save_id);
			delay = 30;
			if(wizardp(me) && (int)me->query("env/test")) delay = 5;
		}
		call_out("liandan_finish",delay*2-1,me,yao,drug_lvl,yaocai_lvl,gain_lvl,value,save_id,1);
	}
	else {
		if(wizardp(me) && (int)me->query("env/test")) delay = 2;
		call_out("liandan_finish",delay*2-1,me,yao,drug_lvl,yaocai_lvl,gain_lvl,value,"",0);
	}

	me->start_busy(delay+1);
	for(i=0;i<n;i++)
		destruct(obj[i]);
	return 1;
}

void liandan_finish(object me,string yao,int drug_lvl,int yaocai_lvl,int gain_lvl,int value,string save_id,int win)
{
	object tools,ob;
	string str;
	int level,i,improve,lower;

	if(!objectp(me) || !userp(me)) return;
	me->start_busy(-1);
	me->interrupt_me();
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("liandan",1);
	if(level>390) level = 390 + (level-390)*11;

	message_vision(HIG"$NϨ����棬�򿪸��ӣ���ͭ¯����ȥ......\n"NOR, me);
	if ( objectp(tools) && tools->query("id")=="yao chui" ) tools->use();

	str = WORKER_D->worker_title(me,"liandan");
	me->set_temp("title", str);

	i = 100 - (level - gain_lvl)/2;
	if(i>200) i = 200;
	if(i< 10) i = 10;
	improve = me->query_int(1) * i/100;

	if( win && yao!="null" ) {
		me->improve_skill("liandan", improve*7);
		if ( environment(me)->query("no_zhiye")
		 || me->query_temp("user_type") == "worker") {
			me->add("combat_exp", random(improve)/3);
			me->add("potential", random(improve)/6);
		}
		ob = new(__DIR__"yao");
		if(!ob) return;
		value  = value * (12+random(21)) / 10;
		if( drug_lvl<=2 && WORKER_D->query_UniqueValues("adddrug",save_id)==0 ) lower=1; else lower=0;
		ob->set_type(yao,(yaocai_lvl+me->query_skill("liandan",1))/2,value,save_id,me,lower);
		ob->set("user_make",1);
		if( !ob->move(me) ) {
			message_vision(HIC"����$N���ϷŲ����ˣ�\n",me);
			ob->move(environment(me));
		}

		tell_room(me,HIC"���ͭ¯���ó�һ"+ob->query("unit")+ob->name()+"��\n"NOR);
		tell_room(environment(me),HIC+me->name()+HIC"��ͭ¯���ó�һ"+ob->query("unit")+"��ҩ��\n"NOR,({me}));
		log_file("career/liandan", sprintf("%-19s:%d:%3d:%d:%s\n",
			ob->query("save_id"),ob->query("imbued"),ob->query("lvl"),ob->query("lower"),ob->short() ), me);
	}
	else {
		if( yao=="null" ) {
			message_vision(HIC"$N��ͭ¯�﷢��һ�����ι�״�ĵ�ҩ��Ҳ��֪�к��á�\n"NOR, me);
			me->improve_skill("liandan", improve);
			if ( environment(me)->query("no_zhiye")
			 || me->query_temp("user_type") == "worker") {
				me->add("combat_exp", random(improve)/9);
				me->add("potential", random(improve)/12);
			}
		}
		else {
			message_vision(HIC"����$N��ͭ¯��ֻ����һ������һ���Ķ�����\n"NOR, me);
			me->improve_skill("liandan", improve*3);
			if ( environment(me)->query("no_zhiye")
			 || me->query_temp("user_type") == "worker") {
				me->add("combat_exp", random(improve)/3);
				me->add("potential", random(improve)/6);
			}
		}
	}
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/liandan",time()+10+random(20));
}
