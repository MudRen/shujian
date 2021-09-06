// zhujianlu.c
// by augx@sj 9/6/2001

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"��¯"NOR, ({ "huo lu" , "lu" }));
	set_weight(1000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
HIR"����һ����ҹ¯��ͨ���Ļ�¯������ͨ�����̵Ļ�¯������ͬ��
��¯����������Ƴɣ������޷�����ĸ��£���ר��������������ģ�\n\n"NOR+
"������������¯����

����(duanzao)��duanzao �������� ԭ��
�����ڿ��Զ���ı����У�sword��xiao��axe��blade��brush��club��
  dagger��fork��hammer��hook��spear��staff��stick��whip��

����(xiu):     xiu ����id

����(gaiming): gaiming ������ ����id
ע�⣺
    1.��Ҫ�������������硺����������֮�࣬ϵͳ���Զ����ϣ�
    2.����ID������� ID + ���� ID��
    3.�����ʹ�� $��ɫ$ �ִ�������ɫ����ɫ˵����help color��
    4.���ֵ������Ҫ�� $NOR$ �ִ���ϵͳ���Զ���ӡ�
    5.����ʹ�ò��Ź۵�����������������ʦ��Ȩ���ջ���ı�����
    6.��ʹ������������������ʦ��Ȩ���ջ���ı�����
");

		set("value", 3000);
		set("no_get", 1);
	}
	setup();
}

void init()
{
	add_action("do_duanzao","duanzao");
	add_action("do_xiu","xiu");
	add_action("do_xiu","fix");
	add_action("do_rename","gaiming");
	add_action("do_rename","rename");

	add_action("do_recover","restore");
}

int do_duanzao(string arg)
{
	object me = this_player() ,obj,obj2,weapon;
	int delay,level,i,j,k,time;
	string type,kuangcai;

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (me->is_fight()) return notify_fail("����æ���أ�\n");
	if (!arg) return notify_fail("��Ҫ����ʲô��\n");
	if ( sscanf(arg,"%s %s",type,kuangcai)<2 )
		return notify_fail("��Ҫ��ʲô����ʲô��\n");
	if ( !objectp(obj = present(kuangcai, me)) )
		return notify_fail("������û������������\n");
	obj = present(obj->query("id"), me);
	if ( !objectp(obj2= present(obj->query("id")+" 2", me)) )
		return notify_fail("�����������"+obj->query("name")+"�����������\n");
	if( !(int)obj->query("kuangcai") || !(int)obj->query("level") )
		return notify_fail("������ֻ���ôӿ�ʯ�����������Ĳ��϶��������\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
		return notify_fail("�����װ���������������졣\n");
	if ( !weapon->query("worker_tool"))
		return notify_fail("�����װ���������������졣\n");
	if ( !wizardp(me) && (time()<(int)me->query("worker/duanzao")) )
		return notify_fail("��ոն�����������о��������ۣ�\n");

	time = time()- me->query("pk_time");
	if ( time < 432000)
		return notify_fail("��Ŀǰ��״̬�޷����졣\n");

	level = (int)me->query_skill("duanzao",1);
	if ( level<1 )
		return notify_fail("������Ͳ�����������\n");

	switch(type){
		case "sword":
		case "axe":
		case "blade":
		case "brush":
		case "club":
		case "dagger":
		case "fork":
		case "hammer":
		case "hook":
		case "spear":
		case "staff":
		case "stick":
		case "xiao":
		case "whip": break;
		default:
			return notify_fail("���ﲻ�ܶ�������������\n");
	}

	switch( (int)obj->query_level() ) {
		case 1: break;
		case 2: if(level<40)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 3: if(level<80)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 4: if(level<120) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 5: if(level<170) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 6: if(level<220) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 7: if(level<270) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 8: if(level<330) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 9: if(level<390) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
	}

	message_vision(HIY"$N��ʼ�Ӹ����Ƕȴ���"+obj->query("name")+HIY"��һ����ԭʼ�Ĳ��ϱ����˫�ı���......\n"NOR, me);

	if(level>390) level = 390 + (level-390)*11;
	switch((int)obj->query_level()) {
		case 1: i = 40;  if(level>100) level=100;j=0; break;
		case 2: i = 80;  if(level>150) level=150;j=0; break;
		case 3: i = 120; if(level>200) level=200;j=1; break;
		case 4: i = 170; if(level>300) level=300;j=1; break;
		case 5: i = 800; if(level>350) level=350;j=2; break;
		case 6: i = 999; if(level>450) level=450;j=2; break;
		case 7: i = 2000;if(level>500) level=500;j=3; break;
		case 8: i = 3000;if(level>500) level=500;j=3; break;
		case 9: i = 9999;if(level>500) level=500;j=4; break;
	}
	if(wizardp(me) && me->query("env/test") && i>500) i=500;

	delay = 10 + random(20);
	k = random(level+i);
	if( k>=((level+i)/2-level/2) && k<=((level+i)/2+level/2) ) {
		if(wizardp(me) && (int)me->query("env/test")) delay = 6;
		if (j>=3) {
			WORKER_D->update_UniqueValues("weapon","","");
			delay = 60;
			if(wizardp(me) && (int)me->query("env/test")) delay = 10;
		}
		call_out("duanzao_makeweapon",delay,me,type,j,obj,delay);
	}
	else {
		if(wizardp(me) && (int)me->query("env/test")) delay = 3;
		call_out("duanzao_finish",delay*2-1,me,obj,0);
	}

	me->start_busy(delay+1);
	destruct(obj2);
	return 1;
}

void duanzao_makeweapon(object me,string type,int qua,object obj,int delay)
{
	object wp,shi;
	string str,st;

	if(!objectp(me) || !userp(me) || !objectp(obj)) return;
/*
        if( qua>=3 && WORKER_D->query_UniqueValues("weapon","") <0 ) {
                tell_object(me , "��������޷�����ͬ�����������㽫�޷�����ߵȼ����У�\n");
                qua = 2;
                delay = 10;
        }
        if( qua==4 && WORKER_D->query_UniqueValues("weapon",me->query("id")) <1 ) {
                tell_object(me , "һ�������Ѿ��ﵽ���������޷����죡\n");
                qua = 2;
                delay = 10;
        }
        if( qua==3 && WORKER_D->query_UniqueValues("weapon2",me->query("id"))<1 ) {
                tell_object(me , "���������Ѿ��ﵽ���������޷����죡\n");
                qua = 2;
                delay = 10;
        }
  */      
	wp = WORKER_D->make_weapon(me,type,qua,obj->query("material"));
	//wp->set("value" , (obj->query("value")*4)/100 * (wp->query("value")/30)/100 );
	wp->set("value" , obj->query("value") * (25+random(40)) / 10 );
	wp->set("weapon_mp/value" , wp->query("value"));
	if(!wp) {
		tell_object(me, "�������ɳ���! \n");
		return;
	}
	if( !environment(this_object()) || !(shi=present("zhujian shi",environment(this_object()))) ) {
		tell_object(me, "�޷��ҵ�����ʦ! \n");
		return;
	}
	if(!wp->move(shi)) {
		tell_object(me, "�����ƶ�����! \n");
		return;
	}
	me->set_temp("worker/wp" , wp);

	if( qua>=3 ) {
		if ( stringp(wp->query("name_st")) && strlen(wp->query("name_st"))>3 )
			st = wp->query("name_st");
		else
			st = "";
		str = sprintf("save_id=%s&time=%d&level=%d&wscore=%d&wuser=%s&wname=%s&details=%s",wp->query("weapon_mp/save_id"),time(),qua+1,
			WORKER_D->weapon_rank(wp),wp->query("maker"),wp->query("name")+"("+wp->query("id")+")",st);
		WORKER_D->update_UniqueValues("addweapon",str,wp->query("weapon_mp/save_id"));
	}
	call_out("duanzao_finish",delay,me,obj,1);
}

void duanzao_finish(object me,object obj,int win)
{
	object tools,wp;
	string str;
	int level, kuangshi, i=1, improve;

	if(!objectp(me) || !userp(me) || !objectp(obj)) return;
	me->start_busy(-1);
	me->interrupt_me();
	tools = me->query_temp("weapon");
	level = (int)me->query_skill("duanzao",1);
	if(level>390) level = 390 + (level-390)*11;
	kuangshi = (int)obj->query_level();

	message_vision(HIY"$N���Ѿ������������εı���������ˮ֮��......\n"NOR, me);
	if ( objectp(tools) && tools->query("id")=="tiechui" ) tools->use();

	switch(kuangshi) {
		case 1: i = 40;  break;
		case 2: i = 80;  break;
		case 3: i = 120; break;
		case 4: i = 170; break;
		case 5: i = 220; break;
		case 6: i = 270; break;
		case 7: i = 330; break;
		case 8: i = 390; break;
		case 9: i = 500; break;
	}
	i = 100 - (level - i)/2;
	if(i>200) i = 200;
	if(i< 10) i = 10;

	if ( me->query_temp("user_type") != "worker")
		improve = me->query_int(1)*i/100;
	else
		improve = me->query_int()*i/100;

	if( win ) {
		me->improve_skill("duanzao", improve*9);
		if ( environment(me)->query("no_zhiye")
		 || me->query_temp("user_type") == "worker") {
			me->add("combat_exp", random(improve*4/5));
			me->add("potential", random(improve/5*3));
		}
		wp = (object)me->query_temp("worker/wp");
		if(!wp) return;
		me->delete_temp("worker/wp");
		if( wp->query("weapon_mp/imbued")>3 && WORKER_D->query_UniqueValues("addweapon",wp->query("weapon_mp/save_id"))<0 ) {
			tell_object(me , "��������޷�����ͬ������������������ʧ�ܣ�\n");
			destruct(wp);
			return;
		}
		if(!wp->move(me)) {
			wp->move(environment(me));
			tell_object(me , "�������ò����ˣ�\n");
		}

		message_vision(HIC"$N��ˮ����ȡ��һ"+wp->query("unit")+wp->name()+"��\n"NOR, me);
	}
	else {
		me->improve_skill("duanzao", improve*3);
		if ( environment(me)->query("no_zhiye")
		 || me->query_temp("user_type") == "worker") {
			me->add("combat_exp", random(improve/3));
			me->add("potential", random(improve/5));
		}
		message_vision(HIC"����$N����ı���һ�ŵ���ˮ����ķ������ˣ�\n"NOR, me);
	}
	destruct(obj);
	if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
		me->set("potential" , me->query("max_pot", 1) );
	me->set("worker/duanzao",time()+10+random(20));

	str = WORKER_D->worker_title(me,"duanzao");
	// ����title
	me->set_temp("title", str);
}

int do_xiu(string arg)
{
	object me = this_player() ,obj,obj2,weapon;
	int delay,level;
	string str;

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (me->is_fight()) return notify_fail("����æ���أ�\n");
	if (!arg) return notify_fail("��Ҫ��ʲô��\n");
	if ( !objectp(obj = present(arg, me)) )
		return notify_fail("������û������������\n");
	if ( !mapp(obj->query("weapon_prop")) || !(int)obj->query("imbued") )
		return notify_fail("������ֻ��ά�����������ı�����\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
		return notify_fail("�����װ������������ά�ޱ�����\n");
	if ( obj->query("weapon_mp/dur") >= obj->query("weapon_mp/max_dur") )
		return notify_fail("����������������������\n");
	if ( obj->query("weapon_mp/dur") <= 0  )
		return notify_fail("��������Ѿ��������ˣ��޷�����\n");

	switch( (string)obj->query("material") ){
		case "xuantie":	  str = WHT"����"NOR; break;
		case "shentie":   str = RED"��������"NOR; break;
		case "jintie":    str = HIY"����"NOR; break;
		case "ruanying":  str = HIW"����"NOR; break;
		case "liuhuashi": str = RED"����ʯ"NOR; break;
		case "lushi":     str = HIG"��ʯ"NOR; break;
		case "ruantie":   str = YEL"����"NOR; break;
		case "shengtie":  str = YEL"����"NOR; break;
		case "qingtong":  str = GRN"��ͭ"NOR; break;
		default: str =	"����";	break;
	}
	if ( !objectp(obj2 = present((string)obj->query("material"), me)) )
		return notify_fail("����Ҫһ��"+str+"������ά�����������\n");

	level = (int)me->query_skill("duanzao",1);
	switch( (int)obj2->query_level() ) {
		case 1: if(level<10)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 2: if(level<40)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 3: if(level<80)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 4: if(level<120) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 5: if(level<170) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 6: if(level<220) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 7: if(level<270) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 8: if(level<330) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 9: if(level<390) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
	}

	message_vision(HIY"$N��ʼ��ϸ��ά��"+obj->query("name")+HIY"����ʱ���������ô��......\n\n"NOR, me);
	delay = 15 + random(30);
	if(wizardp(me) && (int)me->query("env/test")) delay = 3;
	me->start_busy(delay);
	destruct(obj2);
	call_out("xiu_finish",delay*2-1,me,obj);
	return 1;
}

int decvar(object ob,string type,int times,int decmin,int min)
{
	int i,j;

	if( times <= 0 ) return 0;
	i = (int)ob->query(type) * 100;
	if( i == 0 ) return 0;
	decmin *= 100;
	min *= 100;

	j = i / times;
	if( j < decmin ) j = decmin;
	i = i - j;
	if( i < min ) i = min;

	ob->set(type,i/100);
	return i/100;
}

void xiu_finish(object me,object obj)
{
	object tools;
	int i;

	if(!objectp(me) || !userp(me) || !objectp(obj) ) return;

	message_vision(HIY"$N��ϸ��ά��"+obj->query("name")+HIY+"��������»ָ�������ԭò��\n"NOR, me);
	me->improve_skill("duanzao", me->query_int()/2);

	i = decvar(obj,"weapon_mp/max_dur",9,10,100);
	obj->set("dur",i);
	obj->set("weapon_mp/dur",i);
	obj->set("weapon_mp/max_dur",i);

	decvar(obj,"weapon_prop/damage",5+random(7),10,10);
	decvar(obj,"weapon_prop/qi",5+random(7),50,10);
	decvar(obj,"weapon_prop/jing",5+random(7),50,10);
	decvar(obj,"weapon_prop/jingli",5+random(7),50,10);
	decvar(obj,"weapon_prop/neili",5+random(7),50,10);
	decvar(obj,"weapon_prop/attack",5+random(8),3,1);
	decvar(obj,"weapon_prop/dodge",5+random(8),3,1);
	decvar(obj,"weapon_prop/parry",5+random(8),3,1);

	i = decvar(obj,"weapon_mp/rigidity",5,1,1);
	obj->set("rigidity",i);
	i = decvar(obj,"weapon_mp/sharpness",5,1,1);
	obj->set("sharpness",i);
	i = decvar(obj,"weapon_mp/value",6,10,1);
	obj->set("value",i);

	obj->save_weapon(me);

	tools = me->query_temp("weapon");
	if ( objectp(tools) && tools->query("id")=="tiechui" ) tools->use();
}

nosave string *banned_name = ({
// Mud ��������
"ɱ��","����","ѩ��","����","����","�ܹ�","����","����","��ʦ","���","�齣","ɱ�˷�","����","ӭ��",
// Mud ������������
"����","ؤ��","����","����","Ľ��","��Ĺ","ȫ��","����","����","����","�һ�","����",
"������","������","�嶾��","����","а��","��������","�������","�ٸ�","����",
"������","�䵱��","���ư�","��ͨ����","������","����Ľ��","��Ĺ��","��ɽ��","��ɽ��",
"����","������","������",
// ��Ҫ��������
"��ӹ","��Сƽ","������","ë��","���Ż�","�ʵ�","����", "��ϯ",
// С˵����
"������","���޼�","����","���","�����","���","���˷�","ΤС��","Ԭ��־","��һ��",
"�¼���","����","����","�Ƿ�","����","��������","ŷ����","���߹�","��ҩʦ","�λ�ү",
"һ�ƴ�ʦ","������","�ܲ�ͨ","����","������","�������",
// �໰
"ͳһ","����","�����о�","���ִ�","����","�����","ȥ���","������","������","����",
"�쵰","����","ɱ��","����","ǿ��","��Ů","̨��","�쵼","����","ƨ��","ƨ��","����",
"��ƨ","����","����","���","��Ѿ","����","����","����","ɵ��","����","����","�Ҳ�",
"̫��","�¹�","�˸�","����","��", "����", "����", "�ּ�", "��", "����", "����",
});

nosave string *banned_name2 = ({
// ������
"�򹷰�",
"��ɥ��",
"������",
"�����",

"���浶",
"������",
"Ѫ��",
"�쵶","ԧ��","ԧ�쵶",
"�Ͻ�",

"�ƽ��",

"�׺罣","����","��ˮ��","��Ѫ��",
"��������",
"���ս�",
"���±���","�̲���¶��",
"���߽�","���ӽ�",
"��ڤ��",
"��а��",
"�齣","��Ů��",
"��������",
"������",
"���콣","������",
"���佣","�ܹ���",

"������",
"����",
"������",

"�Ż�����",
});

int do_rename(string arg)
{
	object me = this_player() ,obj,obj2,weapon;
	int delay,level,i;
	string str,wp,name,oldname,name2;
	mapping mp;

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
	if (me->is_fight()) return notify_fail("����æ���أ�\n");
	if (!arg) return notify_fail("��Ҫ��ʲô���ֿ���ʲô�����ϣ�\n");
	if (sscanf(arg,"%s %s",name,wp)<2) return notify_fail("��Ҫ��ʲô���ֿ���ʲô�����ϣ�\n");
	if ( !objectp(obj = present(wp, me)) )
		return notify_fail("������û������������\n");
	if ( !mapp(obj->query("weapon_prop")) || !(int)obj->query("imbued") )
		return notify_fail("��ֻ��Ϊ�������ı���������\n");
	if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
		return notify_fail("�����װ������������Ϊ����������\n");
	if ( obj->query("imbued") >3 )
		return notify_fail("�㲻���޸ĸߵȼ����������֡�\n");

	name=replace_string(name,"$RED$",RED,0); name=replace_string(name,"$HIR$",HIR,0);
	name=replace_string(name,"$GRN$",GRN,0); name=replace_string(name,"$HIG$",HIG,0);
	name=replace_string(name,"$YEL$",YEL,0); name=replace_string(name,"$HIY$",HIY,0);
	name=replace_string(name,"$BLU$",BLU,0); name=replace_string(name,"$HIB$",HIB,0);
	name=replace_string(name,"$MAG$",MAG,0); name=replace_string(name,"$HIM$",HIM,0);
	name=replace_string(name,"$CYN$",CYN,0); name=replace_string(name,"$HIC$",HIC,0);
	name=replace_string(name,"$WHT$",WHT,0); name=replace_string(name,"$HIW$",HIW,0);

	name2 = strip(name);
	i = strlen(name2);
	if ( i<2 || i>8 || i%2==1 )
		return notify_fail("��Ҫ�ĵ����ֳ��Ȳ����Ϲ涨��\n");
	while(i--) {
		if (i%2==0 && !is_chinese(name2[i..<1]))
			return notify_fail("�Բ��������á����ġ�ȡ�������֡�\n");
	}
	if ( member_array(name2, banned_name)!=-1 )
		return notify_fail("�����������ֻ���������˵����ţ���������İɡ�\n");

	mp = obj->query("weapon_mp");
	if( !mapp(mp) )	{
		write("������֪ͨ��ʦ��No weapon mapping status��\n");
		return 1;
	}

	oldname = strip(mp["name"]);
	if( mp["skill_type"] == "dagger" ) {
		name += "ذ";
		name2 += "ذ";
	}
	else {
		name += oldname[<2..<1];
		name2 += oldname[<2..<1];
	}
	name += NOR;

	if ( member_array(name2, banned_name2)!=-1 )
		return notify_fail("�����������ֻ���������˵����ţ���������İɡ�\n");

	switch( (string)obj->query("material") ){
		case "xuantie":	  str = WHT"����"NOR; break;
		case "shentie":   str = RED"��������"NOR; break;
		case "jintie":    str = HIY"����"NOR; break;
		case "ruanying":   str = HIW"����"NOR; break;
		case "liuhuashi": str = RED"����ʯ"NOR; break;
		case "lushi":     str = HIG"��ʯ"NOR; break;
		case "ruantie":   str = YEL"����"NOR; break;
		case "shengtie":  str = YEL"����"NOR; break;
		case "qingtong":  str = GRN"��ͭ"NOR; break;
		default: str =	"����";	break;
	}
	if ( !objectp(obj2 = present((string)obj->query("material"), me)) )
		return notify_fail("����Ҫһ��"+str+"������Ϊ�������������\n");

	level = (int)me->query_skill("duanzao",1);
	switch( (int)obj2->query_level() ) {
		case 1: if(level<10)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 2: if(level<40)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 3: if(level<80)  return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 4: if(level<120) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 5: if(level<170) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 6: if(level<220) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 7: if(level<270) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 8: if(level<330) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
		case 9: if(level<390) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
	}

	message_vision(HIY"$N��ʼһ��һ������"+obj->query("name")+HIY"�Ͽ���......\n\n"NOR, me);
	delay = 15 + random(30);
	if(wizardp(me) && (int)me->query("env/test")) delay = 3;
	me->start_busy(delay);
	destruct(obj2);
	call_out("rename_finish",delay*2-1,me,obj,name);
	return 1;
}

void rename_finish(object me,object obj,string name)
{
	object tools;
	mapping mp;
	string * ids;

	if(!objectp(me) || !userp(me) || !objectp(obj) ) return;

	mp = obj->query("weapon_mp");
	mp["name"] = name;
	ids = mp["id"];
	ids[0] = geteuid(me) + " " + ids[2];
	mp["id"] = ids;
	obj->set_name(name, ids);

	obj->save_weapon(me);
	message_vision(HIY"$N�ѱ����������޸�Ϊ"+obj->query("name")+"��\n"NOR, me);

	tools = me->query_temp("weapon");
	if ( objectp(tools) && tools->query("id")=="tiechui" )
		tools->use();
}

#define SAVE_DIR	DATA_DIR + "career/"

int do_recover(string arg)
{
	string str,st;
	mapping mp;
	object ob;
	object me = this_player();

	if( !wizardp(me) ) return 0;
	if( !arg || strlen(arg)<11 ) return notify_fail("�޴���Ʒ��\n");

	seteuid(geteuid(me));

	str = read_file(SAVE_DIR+arg+SAVE_EXTENSION);
	if( strlen(str) < 11 ) return notify_fail("�޴���Ʒ��\n");
	mp = restore_variable( str );
	mp["utime"] = time();

	str = WORKER_D->imbued_object_type(mp["save_id"]);
	if( str == "weapon" )
		ob = WORKER_D->make_weapon(me,mp,0,0);
	else if( str == "armor" )
		ob = WORKER_D->make_armor(me,mp,0,0);
	else
		return notify_fail("��Ʒ��ʽ����\n");

	if(!ob) return notify_fail("������Ʒʱ��������\n");
	ob->move(me);
	tell_object(me,"��ʹ����������ָ���һ"+ob->query("unit")+ob->query("name")+NOR+"��\n");
	rm(SAVE_DIR+arg+SAVE_EXTENSION);

	if(ob->query("imbued")<=3) return 1;

	if( str == "weapon" ) {
		if ( stringp(ob->query("name_st")) && strlen(ob->query("name_st"))>3 )
			st = ob->query("name_st");
		else
			st = "";
		str = sprintf("save_id=%s&time=%d&level=%d&wscore=%d&wuser=%s&wname=%s&details=%s",ob->query("weapon_mp/save_id"),time(),ob->query("imbued"),
			WORKER_D->weapon_rank(ob),ob->query("maker"),ob->query("name")+"("+ob->query("id")+")",st);
		WORKER_D->update_UniqueValues("addweapon",str,ob->query("weapon_mp/save_id"));
	}
	else {
		if ( stringp(ob->query("name_st")) && strlen(ob->query("name_st"))>3 )
			st = ob->query("name_st");
		else
			st = "";
		str = sprintf("save_id=%s&time=%d&level=%d&wscore=%d&wuser=%s&wname=%s&details=%s",ob->query("armor_mp/save_id"),time(),ob->query("imbued"),
			WORKER_D->armor_rank(ob),ob->query("maker"),ob->query("name")+"("+ob->query("id")+")",st);
		WORKER_D->update_UniqueValues("addarmor",str,ob->query("armor_mp/save_id"));
	}

	return 1;
}
