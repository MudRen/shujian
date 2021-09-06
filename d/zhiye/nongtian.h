// nongtian.h
// by augx@sj  10/17/2001

// Modified by mxzhao 2004/03/06 caiji => nongsang

#include <ansi.h>
#include <job_mul.h>

#define EXAM_TICK       30
#define FINISH_TICK     600
#define TIMEOUT_TICK    120
#define DEBUGMODE       0

string* have_items =
	({"mian hua","ya ma","da ma","zhu ma","mu mianhua",});
string* have_items_c =
	({HIW"�޻�",YEL"����",YEL"����",HIY"����",HIY"ľ�޻�",});

void init()
{
	int fib=0;
	int i;
	string biaoji;	
	if(query("outdoors")=="��������"){
		biaoji = "����ũ��˾����";
		fib = 5;
	}
	if(query("show_msg")!=1 && fib>0)
        {
        	biaoji = CHINESE_D->get_title(biaoji)+"    �˵�������ֲ��\n";
		for(i=0;i<fib;i++)
        		biaoji += "\t"+have_items_c[i]+NOR+"("+capitalize(have_items[i])+")"+"\n";
        	biaoji += "\n\t������вɹ����ӡ�\n\tũ����zhongzhi xxxx ��ʼ��ֲ��\n";
        	set("show_msg",1);
        	set("long",query("long")+"    �﹡�߻���һ�����(biaoji)��\n");
        	set("item_desc/biaoji",biaoji);
        	set("no_fight",1);
        }
        add_action("do_zhongzhi","zhongzhi");
        add_action("do_jiaoshui","jiaoshui");
        add_action("do_shifei"  ,"shifei"  );
        add_action("do_shouge"  ,"shouge"  );
        //add_action("do_wah", "wah");
}

int clean_up()
{
        return 1;
}

void decide_action(string u)
{
        if( !mapp(query("user/"+u)) ) return;
        set("user/"+u+"/action" , 1 + random(2) );
        if( !DEBUGMODE ) {
                set("user/"+u+"/atime"  , time() + 1*10 + random(2*10) );
                if( query("user/"+u+"/atime") > (query("user/"+u+"/start")+180) )
                        set("user/"+u+"/action" , 3);
        }
        else {
                set("user/"+u+"/atime"  , time() + 10 + random(20) );
                if( query("user/"+u+"/atime") > (query("user/"+u+"/start")+180) )
                        set("user/"+u+"/action" , 3);
        }
}

void exam()
{
        mapping mp;
        mapping * mpv;
        string  * mpk, *overtime;
        object me;
        int i,count;
        
        remove_call_out("exam");
        
        if( !mapp(mp = query("user")) || (count=sizeof(mp))<1 ) {
                set("exam",0);
                return;
        }       
        mpv = values(mp);
        mpk = keys(mp);
        
        overtime = ({ });
        for(i=0;i<count;i++) {
                if( time() < mpv[i]["atime"] ) continue;
                
                me = present(mpk[i], this_object());
                if( time() > (mpv[i]["atime"]+TIMEOUT_TICK) ) {
                        if(mpv[i]["action"]==3) {
                                if(me && userp(me)) 
                                        tell_object(me,RED"�������ո��ʱ������Ѫ���˷ѵ��ˣ�\n"NOR);
                                overtime += ({ mpk[i] });
                                continue;
                        }
                        else {
                                if(me && userp(me))
                                        tell_object(me,HIR"������" + (mpv[i]["action"]==1?"��ˮ":"ʩ��") + "��ʱ����ֲ�ﳤ���ܵ�Ӱ�졣\n"NOR);
                                mpv[i]["lost"]++;
                                decide_action(mpk[i]);
                        }
                }
                else {
                        if(me && userp(me)) {           
                                switch (mpv[i]["action"]) {
                                        case 1: tell_object(me,GRN"��ø�������ֲ�����ｽˮ�ˡ�\n"NOR); break;
                                        case 2: tell_object(me,GRN"��ø�������ֲ������ʩ���ˡ�\n"NOR); break;
                                        case 3: tell_object(me,HIG"������ֲ��ֲ���Ѿ����죬����Կ�ʼ�ո��ˡ�\n"NOR); break;
                                }                                       
                        }
                }
        }
        
        for(i=0;i<sizeof(overtime);i++)
                delete( "user/" + overtime[i] );
        
        if( !mapp(mp=query("user")) || sizeof(mp)<1 )
                set("exam",0);
        else
                call_out("exam",EXAM_TICK);
}

//////////////////////////////////////////////////////////////////////////////
int do_zhongzhi(string arg)
{
        object me = this_player() ,weapon ,zhongzi;
        int level,delay;
        
        if( !arg ) return notify_fail("��Ҫ��ֲʲô��\n");      
        if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tieqiao" )
                return notify_fail("�����װ�����²�����ֲ��\n");
        if ( me->is_busy() )
                return notify_fail("����æ���أ�\n");   
        level = (int)me->query_skill("nongsang",1);
        if ( level<1 ) return notify_fail("������Ͳ���ũɣ���ܰ����ǲ�����ѧϰһЩũɣ����(nongsang)������ֲ������\n");
        if ( mapp(query("user/"+me->query("id"))) )
                return notify_fail("���Ѿ���ʼ��ֲ��ѽ��\n");
        if ( !objectp(zhongzi = present(arg, me)) )
                return notify_fail("������û������������\n");
        if( !(int)zhongzi->query("zhongzi") )
                return notify_fail("�㲻����������������ֲ��\n");
                
        switch( zhongzi->query_level() ) {
                case 1: break;
                case 2: if(level<40)  return notify_fail("���ũɣ���ܲ�����\n"); break;
                case 3: if(level<80)  return notify_fail("���ũɣ���ܲ�����\n"); break;
                case 4: if(level<120) return notify_fail("���ũɣ���ܲ�����\n"); break;
                case 6: if(level<220) return notify_fail("���ũɣ���ܲ�����\n"); break;
                default: return notify_fail("�㲻����ֲ����ֲ�\n"); break;
        }
                
        set("user/"+me->query("id")+"/start", time());
        set("user/"+me->query("id")+"/product", zhongzi->query_level());
        set("user/"+me->query("id")+"/lost", 0);
        decide_action(me->query("id"));
        if( !query("exam") ) {
                call_out("exam",EXAM_TICK);
                set("exam",1);
        }

        destruct(zhongzi);      
        message_vision(HIY"$N��ʼ����������......\n\n"NOR, me);
        delay = 3 + random(2);
        if(wizardp(me) && (int)me->query("env/test")) delay = 6;
        me->start_busy(delay+1);
        call_out("zhongzhi_finish",delay/3,me,1,delay);
        
        return 1;
}

void zhongzhi_finish(object me,int step,int delay)
{
        object tools;
        int i;
        
        if(!me) return;
        switch (step) {
                case 1: message_vision(HIY"Ȼ��$N����������һ����......\n"NOR, me); break;
                case 2: message_vision(HIY"$N�����ӷŵ�����......\n"NOR, me); break;
                case 3: message_vision(HIY"$NС�ĵİѿ����......\n"NOR, me); break;
                case 4: message_vision(HIY"$N��ʼ�������Ͻ�ˮ......\n"NOR, me); break;
                case 5: message_vision(HIY"$N��ʼ��������ʩ��......\n"NOR, me); break;
                case 6: message_vision(YEL"$N�����ֺ��ˣ�\n"NOR, me); 
                        me->start_busy(-1);
                        me->interrupt_me();
                        for(i=0;i<3;i++) {
                                if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="tieqiao" )
                                        tools->use();
                        }
                        return;
        }
        call_out("zhongzhi_finish",delay/3,me,step+1,delay);
}

//////////////////////////////////////////////////////////////////////////////
int do_jiaoshui(string arg)
{
        object me = this_player();
        int delay;
        
        if( objectp( me->query_temp("weapon") ) )
                return notify_fail("�������ֲ��ܽ�ˮ����\n");         
        if( me->is_busy() )
                return notify_fail("����æ���أ�\n");
        if( !mapp(query("user/"+me->query("id"))) )
                return notify_fail("�㻹û�п�ʼ��ֲ���ҽ�ʲôˮ����\n");
        if( query("user/"+me->query("id")+"/action") != 1
         || query("user/"+me->query("id")+"/atime") > time() )
                return notify_fail("�����ڲ���Ҫ��ˮ��\n");
                
        decide_action(me->query("id"));

        message_vision(HIW"$N������Ե�ˮ��������Щˮ����ʼ����......\n\n"NOR, me);
        delay = 3 + random(2);
        if(wizardp(me) && (int)me->query("env/test")) delay = 2;
        me->start_busy(delay+1);
        call_out("jiaohua_finish",delay*2-1,me);
        
        return 1;
}

void jiaohua_finish(object me)
{
        if(!me) return;
        me->start_busy(-1);
        me->interrupt_me();
        message_vision(HIW"$N�۵���ͷ�󺹣����㽽���˵ء�\n"NOR, me);
}

//////////////////////////////////////////////////////////////////////////////
int do_shifei(string arg)
{
        object me = this_player(),weapon;
        int delay;
        
        if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="tieqiao" )
                return notify_fail("�����װ�����²���ʩ�ʡ�\n");
        if( me->is_busy() )
                return notify_fail("����æ���أ�\n");
        if( !mapp(query("user/"+me->query("id"))) )
                return notify_fail("�㻹û�п�ʼ��ֲ����ʩʲô�ʰ���\n");
        if( query("user/"+me->query("id")+"/action") != 2
         || query("user/"+me->query("id")+"/atime") > time() )
                return notify_fail("�����ڲ���Ҫʩ�ʡ�\n");
                
        decide_action(me->query("id"));

        message_vision(HIY"$N������Եķ��Ͽ������Щ���ϣ���ʼʩ��......\n\n"NOR, me);
        delay = 3 + random(2);
        if(wizardp(me) && (int)me->query("env/test")) delay = 2;
        me->start_busy(delay+1);
        call_out("shifei_finish",delay*2-1,me);
        
        return 1;
}

void shifei_finish(object me)
{
        object tools;
        if(!me) return;
        me->start_busy(-1);
        me->interrupt_me();
        message_vision(HIY"$N�۵���ͷ�󺹣����������ʩ�ʵĹ�����\n"NOR, me);
        if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="tieqiao" )
                tools->use();   
}

//////////////////////////////////////////////////////////////////////////////
int do_shouge(string arg)
{
        object me = this_player(),weapon;
        int delay;
        
        if( !objectp(weapon=me->query_temp("weapon")) || weapon->query("id")!="lian dao" )
                return notify_fail("�����װ�����������ո\n");
        if( me->is_busy() )
                return notify_fail("����æ���أ�\n");
        if( !mapp(query("user/"+me->query("id"))) )
                return notify_fail("�㻹û�п�ʼ��ֲ���ո�ʲô��\n");
        if( query("user/"+me->query("id")+"/action") != 3
         || query("user/"+me->query("id")+"/atime") > time() )
                return notify_fail("���ڻ�û�е��ո���ء�\n");

        decide_action(me->query("id"));

        message_vision(YEL"$N�˸߲��ҵĿ�ʼ�ո�......\n\n"NOR, me);
        delay = 3 + random(3);
        if(wizardp(me) && (int)me->query("env/test")) delay = 2;
        me->start_busy(delay+1);
        call_out("shouge_finish",delay*2-1,me);
        
        return 1;
}

void shouge_finish(object me)
{
        object tools,obj;
        int i,j,k,level,improve,bu;
        mapping mp;
        float updown;
        
        if( !me ||!userp(me) ) return;
        me->start_busy(-1);
        me->interrupt_me();
        if( !mapp(mp = query("user/"+me->query("id"))) ) return;
        level = (int)me->query_skill("nongsang",1);
        if(level>390) level = 390 + (level-390)*11;
        
        for(i=0;i<3;i++) {
                if ( objectp(tools = me->query_temp("weapon")) && tools->query("id")=="lian dao" )
                        tools->use();
        }
        
        switch ( mp["product"] ) {
                case 1: i = 40;  break;
                case 2: i = 80;  break;
                case 3: i = 120; break;
                case 4: i = 170; break;
                case 6: i = 270; break;
        }       
        if ( i>(level*2) ) i=level*2;
        
        improve = me->query_int(1)*i/level;
        improve /= 3;
        
        switch( mp["product"] ) {
                case 1: i = 40;  break;
                case 2: i = 80;  break;
                case 3: i = 120; break;
                case 4: i = 180; break;
                case 6: i = 330; break;
        }
        if( level > i ) level = i;
        
        updown = WORKER_D->updown(me,"nongsang");
        bu = to_int((13 * 100 * level / i)*updown) ;
        bu = bu*2/3 + random(bu*2/3);
        if( mp["lost"] ) bu = bu - bu * (1+mp["lost"]*2)/10;
        bu = bu / 100;
        if(bu<1) bu=1;
        
        j = 0;
        for(i=0;i<bu;i++) {
        	obj = WORKER_D->mater_random(me,2,mp["product"]);
		if(!obj) return;
                obj->move(environment(me));
                if( !obj->move(me) ) {
                        j = 1;
                        if( sizeof(all_inventory(environment(me))) > 49 )
                                destruct(obj);
                }
        }
        
        message_vision(YEL"$N�ܹ��ջ���"+CHINESE_D->chinese_number(bu)+obj->query("unit")+obj->name()+"��\n"NOR, me);
        if(j) message_vision(YEL"����$N�ò�����ô�ֻ࣬�ðѼ�"+obj->query("unit")+obj->name()+"�ŵ����ϡ�\n"NOR, me);
        
        improve *= bu;
        improve = improve*2/3 + random(improve*2/3);
        //improve = improve*ZY_NONGSANG_MUL/100;
        i = improve * 12;
        WORKER_D->check_impove(me,"nongsang",i,2);
        j = random(improve)/2;
                
        j = me->add_exp_combat( j ,0,"ũɣ",1);
        //me->add("combat_exp", j);
                
        k = random(improve)/4;  me->add("potential", k);
        if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
                me->set("potential" , me->query("max_pot", 1) );

        log_file("job/wnongsang",sprintf("%s(%s)��bu:%d,lvl:%d;cj:%d,exp:%d,pot:%d;ncj:%d,nexp:%d\n", 
                me->name(),me->query("id"),bu,mp["product"],i,j,k,me->query_skill("nongsang",1),me->query("combat_exp")),me);
        delete("user/"+me->query("id"));
}
