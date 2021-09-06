// zhujianlu.c
// by augx@sj 9/6/2001
// modified by Ciwei@SJ

#include <ansi.h>
#include <job_mul.h>
inherit ITEM;

string long();
int check(object me);
int duanzao_it(object me,string arg);

void create()
{
        set_name(HIR"��¯"NOR, ({ "huo lu" , "lu" }));
        set_weight(1000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(:long:) );
                set("value", 3000);
                set("no_get", 1);
        }
        setup();
       /*
       ����(gaiming): gaiming ������ ����id
ע�⣺
    1.��Ҫ�������������硺����������֮�࣬ϵͳ���Զ����ϣ�
    2.����ID������� ID + ���� ID��
    3.�����ʹ�� $��ɫ$ �ִ�������ɫ����ɫ˵����help color��
    4.���ֵ������Ҫ�� $NOR$ �ִ���ϵͳ���Զ���ӡ�
    5.����ʹ�ò��Ź۵�����������������ʦ��Ȩ���ջ���ı�����
    6.��ʹ������������������ʦ��Ȩ���ջ���ı�����
    */
}

string long()
{
	string str;
	object me;
			
str = HIR"����һ����ҹ¯��ͨ���Ļ�¯������ͨ�����̵Ļ�¯������ͬ��
��¯����������Ƴɣ������޷�����ĸ��£���ר��������������ģ�\n\n"NOR+
"������������¯����

����(duanzao)��duanzao �������� ԭ�� [with �屦]
�����ڿ��Զ���ı����У�sword��xiao��axe��blade��brush��club��
  dagger��fork��hammer��hook��spear��arrow , staff��stick��whip��

����(xiu):     xiu ����id
";
	me = this_player();
	if(!me) return str;
	if(check(me))
		return str+"\n\n����ʦ��һ������գ��գ�ۡ�\n";
	return str;
}

int check(object me)
{
	if(!me) return 0;
	//return (me->query("imbue_weapon") && (time()-me->query("imbue_weapon")) <3600);
	return !userp(me);
}

void init()
{
        add_action("do_duanzao","duanzao");
        add_action("do_xiu","xiu");
        add_action("do_xiu","fix");
       // add_action("do_rename","gaiming");
        //add_action("do_rename","rename");
        //add_action("do_recover","restore");
        
        if(inherits(ROOM,environment(this_object()))!=0	) environment(this_object())->set("no_fight",1);
}

int do_duanzao(string arg)
{
        object me = this_player();
        return duanzao_it(me,arg);
}

int duanzao_it(object me,string arg)
{
	object obj,obj2,weapon,fujia;
        int delay,level,i,j,k,time;
        string* status = ({});
        mapping temp;
        float updown;
        //float power;
        string type,kuangcai;
        string jade;//hehe
        mapping myskill;
        mapping shuxing = ([]);
        
	level = (int)me->query_skill("duanzao",1);
        if (!check(me) && me->is_busy()) return notify_fail("����æ���أ�\n");
        if (!check(me) && me->is_fight()) return notify_fail("����æ���أ�\n");
        if (!arg) return notify_fail("��Ҫ����ʲô��\n");
        if ( sscanf(arg,"%s %s",type,kuangcai)<2 )
                return notify_fail("��Ҫ��ʲô����ʲô��\n");
	
	if(check(me)) level=999;
	
        if(sscanf(kuangcai,"%s with %s",kuangcai,jade)==2)
        {
        	if ( !objectp(fujia = present(jade, me)) )
                return notify_fail("������û������������\n");
                if ( !objectp(obj = present(kuangcai, me)) )
                return notify_fail("������û������������\n");
                
                if(fujia->query("material_for")!="weapon") return notify_fail("�����ҿ��ܾ���"+fujia->name()+"��"+obj->name()+"�����ʡ�\n");
                switch( (int)fujia->query("material_level") ) {
                case 1: break;
                case 2: if(level<120) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
                case 4: if(level<220) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
                case 6: if(level<330) return notify_fail("��Ķ��켼�ܲ�����\n"); break;                
                case 8: if(level<390) return notify_fail("��Ķ��켼�ܲ�����\n"); break;                
                case 10: if(level<400) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
        	}
	}
        if ( !objectp(obj = present(kuangcai, me)) )
                return notify_fail("������û������������\n");
        obj = present(obj->query("id"), me);
        if ( !objectp(obj2= present(obj->query("id")+" 2", me)) )
                return notify_fail("�����������"+obj->query("name")+"�����������\n");
        if( !(int)obj->query("kuangcai") || !(int)obj->query("level") )
                return notify_fail("������ֻ���ôӿ�ʯ�����������Ĳ��϶��������\n");
        if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
                return notify_fail("�����װ���������������졣\n");
        if (!check(me) && !weapon->query("worker_tool"))
                return notify_fail("�����װ���������������졣\n");
        if (!check(me) && !wizardp(me) && (time()<(int)me->query("worker/duanzao")) )
                return notify_fail("��ոն�����������о��������ۣ�\n");

        time = time()- me->query("pk_time");
        if (!check(me) && time < 4300)
                return notify_fail("��Ŀǰ��״̬�޷����졣\n");	
	                       
        if (!check(me) && level<1 )
                return notify_fail("������Ͳ������������ǲ�����ѧϰһЩ���켼��(duanzao)������������������\n");

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
//                 case "arrow":
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
                case 10: if(level<400) return notify_fail("��Ķ��켼�ܲ�����\n"); break;
        }
        
        myskill = me->query("forging");//����Quest��
        
        if (!check(me) && !mapp(myskill)) return notify_fail("�㻹�����κι������ܣ�\n");
        
	if (!check(me) && member_array(type,keys(myskill)) == -1)
		return notify_fail("�����������������˽ⲻ�࣬��������죡\n");
	
	if(level>220) k = 10000*level*(int)obj->query_level()/15;
	else k = 10000*level*(int)obj->query_level()/20;
	if(me->query("registered")==3) k = k*2/3;
	if(!check(me) && k>=10000){
		switch(MONEY_D->player_pay(me, k,0,1))
		{
			case 0:return notify_fail("����Ǯׯ�Ĵ���֧���˴ζ��졣\n");
			default:write("��Ϊ�˴ζ���֧����"+MONEY_D->money_str(k)+"��\n");
		}
		/*
		if(me->query("balance")<k) return notify_fail("����Ǯׯ�Ĵ���֧���˴ζ��졣\n");
		me->add("balance",-k);
		write("��Ϊ�˴ζ���֧����"+MONEY_D->money_str(k)+"��\n");
		*/
	}
	        
        shuxing = WORKER_D->map_add(shuxing,obj->query("material_prop"));
        shuxing = WORKER_D->map_add(shuxing,obj2->query("material_prop"));
        if(objectp(fujia))
        {
        	temp = fujia->query("material_props");
        	if(mapp(temp)) status = copy(values(temp));
        	shuxing = WORKER_D->map_add(shuxing,fujia->query("material_prop"));
        } 
        
        me->delete("imbue_weapon");
        
        message_vision(HIY"$N��ʼ�Ӹ����Ƕȴ���"+obj->query("name")+HIY"��һ����ԭʼ�Ĳ��ϱ����˫�ı���......\n"NOR, me);
        me->set_temp("pending/duanzao",1);
	level = (int)me->query_skill("duanzao",1);
        if(level>390) level = 390 + (level-390)*11;
        switch((int)obj->query_level()) {
                case 1: i = 40;  if(level>100) level=100;j=0; break;
                case 2: i = 80;  if(level>150) level=150;j=0; break;
                case 3: i = 120;j=0;
                	if(level>200) j +=random(2);
                	if(level>200) level=200;break;
                case 4: i = 170; if(level>300) level=300;j=1; break;
                case 5: i = 800;j=1;
                	if(level>350) j +=random(2);
                	if(level>350) level=350;break;
                case 6: i = 999; if(level>450) level=450;j=2; break;
                case 7: i = 2000;j=2;
                	if(level>440) j +=random(2);
                	if(level>500) level=500;break;
                case 8: i = 3000;if(level>500) level=500;j=3; break;
                case 9: i = 9999;j=3;
                	if(level>500) j +=random(2);
                	if(level>500) level=500;break;
                case 10: i = 20000;if(level>600) level=600;j=4; break;
        }
        if(wizardp(me) && me->query("env/test") && i>500) i=500;

        delay = 1;
        k = random(level+i);        
        
        updown = WORKER_D->updown(me,type);
        //if( objectp(fujia) || ( k>=((level+i)/2-level/2) && k<=((level+i)/2+level/2) ) )  
        if( objectp(fujia) || ( k>=to_int(((level+i)/2-level/4)/updown) && k<=to_int(((level+i)/2+level/4)*updown)  ) ) {
                if(wizardp(me) && (int)me->query("env/test")) delay = 6;
                if (j>=3) {
                        WORKER_D->update_UniqueValues("weapon","","");
                        delay = 1;
                        if(wizardp(me) && (int)me->query("env/test")) delay = 1;
                }
                call_out("duanzao_makeweapon",delay,me,type,j,obj,delay,shuxing,status);//ʹ���������ɹ���100% ԭ���ɹ����µ�
        }
        else {
                if(wizardp(me) && (int)me->query("env/test")) delay = 3;
                call_out("duanzao_finish",delay*2-1,j,me,obj,0);
        }

        me->start_busy(delay+1);
        destruct(obj2);
        if(objectp(fujia)) destruct(fujia);
        return 1;
}

void duanzao_makeweapon(object me,string type,int qua,object obj,int delay,mapping shuxing,string* status)
{
        object wp,shi;
        string str,st;

        if(!objectp(me) || !objectp(obj)) return;
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
        wp = WORKER_D->make_weapon(me,type,qua,obj->query("material"),shuxing,status);
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
                //WORKER_D->update_UniqueValues("addweapon",str,wp->query("weapon_mp/save_id"));
        }
        call_out("duanzao_finish",delay,qua,me,obj,1);
	
}

void duanzao_finish(int j,object me,object obj,int win)
{
        object tools,wp;
        string str;
        int level, kuangshi, i=1, improve;

        if(!objectp(me) ||!objectp(obj)) return;
        me->start_busy(-1);
        me->interrupt_me();
        tools = me->query_temp("weapon");
        level = (int)me->query_skill("duanzao",1);
        if(level>390) level = 390 + (level-390)*11;
        kuangshi = (int)obj->query_level();

        message_vision(HIY"$N���Ѿ������������εı���������ˮ֮��......\n"NOR, me);
        me->delete_temp("pending/duanzao",1);
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
        	WORKER_D->check_impove(me,"duanzao",improve*9,j>=4?3:2);
                //if(me->query_skill("duanzao",1)<220) me->improve_skill("duanzao", improve*9);
                if ( environment(me)->query("no_zhiye")
                 || me->query_temp("user_type") == "worker")
                 {
					int exp = me->add_exp_combat( random(improve*4/5) ,0,"����",1);
					//me->add("combat_exp", random(improve*4/5)*ZY_ZHUJIAN_MUL/100  );
					//< Modified by mxzhao 2005/01/09
					//me->add("potential", random(improve/5*3)*ZY_ZHUJIAN_MUL/100  );
					me->add("potential", exp*3/4);
					//> Modified by mxzhao 2005/01/09
                }
                wp = (object)me->query_temp("worker/wp");
                if(!wp) return;
                me->delete_temp("worker/wp");
                //if( wp->query("weapon_mp/imbued")>3 && WORKER_D->query_UniqueValues("addweapon",wp->query("weapon_mp/save_id"))<0 ) {
                  //      tell_object(me , "��������޷�����ͬ������������������ʧ�ܣ�\n");
                    //    destruct(wp);
                      //  return;
                //}
                if(!wp->move(me)) {
                        wp->move(environment(me));
                        tell_object(me , "�������ò����ˣ�\n");
                }
                
                message_vision(HIC"$N��ˮ����ȡ��һ"+wp->query("unit")+wp->name()+"��\n"NOR, me);
                if(check(me)) me->back_player(wp);
        }
        else {
        	WORKER_D->check_impove(me,"duanzao",improve*3,2);
                //if(me->query_skill("duanzao",1)<220) me->improve_skill("duanzao", improve*3);
                if ( environment(me)->query("no_zhiye")
					|| me->query_temp("user_type") == "worker") {
					int exp = me->add_exp_combat( random(improve/3) ,0,"����",1);
					//me->add("combat_exp", random(improve/3) *ZY_ZHUJIAN_MUL/100 );
					//< Modified by mxzhao 2005/01/09
					//me->add("potential", random(improve/5) *ZY_ZHUJIAN_MUL/100 );
					me->add("potential", exp*3/5);
					//> Modified by mxzhao 2005/01/09
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
        int delay,level,flag;
        string str;

        if (me->is_busy()) return notify_fail("����æ���أ�\n");
        if (me->is_fight()) return notify_fail("����æ���أ�\n");
        if (!arg) return notify_fail("��Ҫ��ʲô��\n");
        if ( !objectp(obj = present(arg, me)) )
                return notify_fail("������û������������\n");        
        if ( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tiechui" )
                return notify_fail("�����װ������������ά�ޱ�����\n");
	//if(!obj->query("broken"))
		//return notify_fail("���������δ��ȫ�𺦣�����Գ���(repair)��������\n");
	if(!mapp(obj->query_temp("apply/weapon_mp_old")) && (!mapp(obj->query("weapon_prop")) || !(int)obj->query("imbued") ) )
		return notify_fail("������ֻ��ά�����������ı�����\n");
        if (!obj->query("broken") &&  obj->query("weapon_mp/dur") >= obj->query("weapon_mp/max_dur") )
                return notify_fail("����������������������\n");
	//if ( !mapp(obj->query("weapon_prop")) || !(int)obj->query("imbued") )
                //return notify_fail("������ֻ��ά�����������ı�����\n");
        //if ( obj->query("weapon_mp/dur") <= 0  )
                //return notify_fail("��������Ѿ��������ˣ��޷�����\n");
		
	flag = strsrch(obj->query("save_id"),"weilan tiejiang")==0;
	
        switch( (string)obj->query("material") ){
                case "xuantie":   str = WHT"����"NOR; break;
                case "shentie":   str = RED"��������"NOR; break;
                case "jintie":    str = HIY"����"NOR; break;
                case "ruanying":  str = HIW"����"NOR; break;
                case "liuhuashi": str = RED"����ʯ"NOR; break;
                case "lushi":     str = HIG"��ʯ"NOR; break;
                case "ruantie":   str = YEL"����"NOR; break;
                case "shengtie":  str = YEL"����"NOR; break;
                case "qingtong":  str = GRN"��ͭ"NOR; break;
                default: str =  "����"; break;
        }
        if (!flag && !objectp(obj2 = present((string)obj->query("material"), me)) )
                return notify_fail("����Ҫһ��"+str+"������ά�����������\n");

        level = (int)me->query_skill("duanzao",1);
        if(!flag) switch( (int)obj2->query_level() ) {
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
        if(flag)
        	switch(MONEY_D->player_pay(me,obj->query("value")/2))
        	{
        		case 1:break;
        		default:return notify_fail("�������Ǯ�����ˣ�����Ҫ"+MONEY_D->money_str(obj->query("value")/2)+"������á�\n");
        	}
        message_vision(HIY"$N��ʼ��ϸ��ά��"+obj->query("name")+HIY"����ʱ���������ô��......\n\n"NOR, me);
        delay = 15 + random(30);
        if(wizardp(me) && (int)me->query("env/test")) delay = 3;
        me->start_busy(delay);
        if(!flag && obj2) destruct(obj2);
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
        
        
	obj->delete("broken");
	obj->delete("treasure");
			        
        if(obj->query_temp("apply/weapon_mp_old")) obj->set("weapon_mp",obj->query_temp("apply/weapon_mp_old") );
	if(obj->query_temp("apply/name_old")) obj->set("name",obj->query_temp("apply/name_old"));
	if(obj->query_temp("apply/weapon_prop_old")) obj->set("weapon_prop",obj->query_temp("apply/weapon_prop_old"));
	if(obj->query_temp("apply/long_old")) obj->set("long",obj->query_temp("apply/long_old"));
	
	obj->delete_temp("apply");
	
        message_vision(HIY"$N��ϸ��ά��"+obj->query("name")+HIY+"��������»ָ�������ԭò��\n"NOR, me);
        WORKER_D->check_impove(me,"duanzao",me->query_int()/2,2);
        //me->improve_skill("duanzao", me->query_int()/2);

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
        
        obj->set("weapon_mp/weapon_prop",copy(obj->query("weapon_prop")));

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
