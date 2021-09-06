#include <ansi.h>
#include <job_mul.h>
inherit NPC;
string ask_job();
string ask_finish();
void create()
{
        set_name("¿àÍ·ÍÓ",({"ku toutuo", "ku"}));
        set("long", "Ò»¸ö³¤·¢Åû¼çµÄÍ·ÍÓ£¬Éí²Ä¿ıÎ°£¬ÂúÃæºáÆßÊú°ËµÄ¶¼ÊÇµ¶°Ì£¬±¾À´ÏàÃ²ÒÑÈ«²»¿É±æ¡£\n");
        set("age", 56);
        set("attitude", "peaceful");
        set("shen", -10000);
        set("str", 26);
        set("per", 28);
        set("int", 29);
        set("con", 27);
        set("dex", 30);
        set("max_qi", 3500);
        set("max_jing", 2200);
        set("eff_jingli", 2500);
        set("jiali", 80);
        set("combat_exp", 1500000);
        set("unique", 1);

        set_skill("sword",170);
        set_skill("dodge",170);
        set_skill("force", 170);
        set_skill("blade",170);
        set_skill("literate",150);
        set_skill("hand",170);
        set_skill("strike",170);
        set_skill("hanbing-mianzhang",170);
        set_skill("yingzhua-shou",170);
        set_skill("piaoyi-shenfa", 170);
        set_skill("shenghuo-shengong", 170);
        set_skill("lieyan-dao",170);
        set_skill("liehuo-jian",170);
        set_skill("parry", 170);

        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("sword", "liehuo-jian");
        map_skill("parry", "liehuo-jian");
        map_skill("blade", "lieyan-dao");
        map_skill("hand", "yingzhua-shou");
        map_skill("strike", "hanbing-mianzhang");
        prepare_skill("strike", "hanbing-mianzhang");
        prepare_skill("hand","yingzhua-shou");

        set("inquiry", ([
                 "Óª¾È" : (: ask_job :),
                 "ÍÑÏÕ" : (: ask_finish :),
        ]));
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object("/d/mingjiao/obj/white-cloth")->wear();
}

int check_ip(object *team)
{
        int i, j;
        for (i = 0;i < sizeof(team);i ++)
                for (j = i + 1;j < sizeof(team);j ++)
                        if (team[i] && query_ip_number(team[i]) == query_ip_number(team[j]))
                                return 0;
        return 1;
}

void reset_room(int num)
{
        int i;
        for (i = 1;i <= 13;i ++)
        {
                "/cmds/app/update"->main(this_object(), "/d/jingcheng/wanan-si/baota-" + i);
                ("/d/jingcheng/wanan-si/baota-" + i)->setup_shouwei(num + random(3));
        }
}

string ask_job()
{
        object me = this_player(), *team = me->query_team();
        int i, max, min, total = 0;
        object ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
        
        foreach (object user in ob_list)
                if (user->query_temp("was_job"))
                        return "ÕıÓĞÈËÔÚÍò°²ËÂÄÚ¾ÈÈË£¬²»ÀÍ´ó¼İÁË¡£\n";
        if (sizeof(team) < 2)
                return "¾ÈÈËÖ®ÊÂÊ®·ÖÎ£ÏÕ£¬½öÆ¾Ò»ÈËÖ®Á¦¿ÖÅÂ²»ÄÜÊ¤ÈÎ¡£\n";
        if (sizeof(team) > 3)
                return "Íò°²ËÂÄÚ·ÀÊØ¼«ÆäÑÏÃÜ£¬ÈËÊıÌ«¶à¸üÈİÒ×±©Â¶¡£\n";
        if (team[0] != me) 
                return "Ö»ÓĞ¶ÓÎéµÄÊ×Áì²Å¿ÉÒÔ´ø¶Ó¾ÈÈË¡£\n";
        if (!check_ip(team))
                return "ÄãµÄ¶ÓÎéÓĞÎÊÌâ£¬ÎŞ·¨¸øÄãÈÎÎñ¡£\n";
                
        max = min = me->query("combat_exp");
        for (i = 0;i < sizeof(team);i ++)
        {
                if (!team[i])
                        return "ÄãµÄ¶ÓÎé³öÏÖÁËÎÊÌâ£¬Çë½âÉ¢²¢ÖØĞÂ×é½¨¡£";
                if (!present(team[i]))
                        return "ÔõÃ´ºÃÏóÈË²»È«°¡£¿" + team[i]->query("name") + "ÔõÃ´Ã»À´£¿\n";
              if (team[i]->query("combat_exp") < 2000000)
                        return "¾ÈÈËÖ®ÊÂÊ®·ÖÎ£ÏÕ£¬" + team[i]->query("name") + "¿ÖÅÂ²»ÄÜÊ¤ÈÎ¡£\n";
                if (team[i]->query_condition("was_job"))
                        return "Äã¶ÓÎéÖĞµÄ" + team[i]->query("name") + "ÒÑ¾­Ê®·ÖĞÁ¿à£¬»»ÆäËûÈË°É¡£\n";

                if (me == team[i])
                        continue;
                if (!interactive(team[i]))
                        return "Äã»¹ÊÇ½«" + team[i]->query("name") + "»»³ÉÆäËûÈË°É¡£\n";
                total += team[i]->query("combat_exp");
                if (team[i]->query("combat_exp") > max)
                        max = team[i]->query("combat_exp"); 
                if (team[i]->query("combat_exp") < min)
                        min = team[i]->query("combat_exp");
        }
        if ((total < 1000000))
                return "¾ÈÈËÖ®ÊÂÊ®·ÖÎ£ÏÕ£¬¿ÖÅÂÄãÃÇ²»ÄÜÊ¤ÈÎ¡£\n";
        if (min / (max / 100) < 80)
                return "¾ÈÈËÖ®ÊÂÊ®·ÖÎ£ÏÕ£¬ÄãÃÇµÄ²î¾àÌ«´óÁË¡£\n";
        
        command("say ËÂÄÚÊ®·ÖÎ£ÏÕ£¬Îñ±ØĞ¡ĞÄ£¡");
//         CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HBMAG+HIW"%s×é¶Ó¿ªÊ¼Íò°²ËÂÓª¾ÈÈÎÎñ£¡", me->name(1)));
        reset_room(sizeof(team));
        for (i = 0;i < sizeof(team);i ++)
        {
                team[i]->delete_temp("was_job");
                team[i]->set_temp("was_job/asked", 1);
                team[i]->set_temp("was_job/num", sizeof(team));
                team[i]->apply_condition("job_busy", 20);
                team[i]->apply_condition("was_job", 90);
                team[i]->apply_condition("was_check",90);
                team[i]->set("job_name", "Íò°²ËÂ¾ÈÈË");
                team[i]->move("/d/jingcheng/wanan-si/wanan-siyuan");
                tell_object(team[i], HIR"ÄãÀ´µ½±¦ËşÇ°£¬·¢ÏÖ±¦ËşÒÑ¾­Æğ»ğ£¬¾ÈÈËÆÈÔÚÃ¼½Ş£¡\n"NOR);
        }
        return "Ï£Íû´ËĞĞÒ»ÇĞË³Àû¡£\n";
}

string ask_finish()
{
        object me = this_player(), *team = me->query_team();
        object xy_letter;
        int i,j,z,exp,shen,pot,SJCredit,gold,gold2,dbexp,ext;
        
        if (!me->query_temp("was_job/asked"))
                        return "ÄãÃ»ÁìÈ¡¹ıÈÎÎñ,²»ÒªÀ´µ·ÂÒ¡£\n";

        if (sizeof(team) != 0 && (team[0]!=me))
		  return "Ö»ÓĞ¶ÓÎéµÄÊ×Áì²Å¿ÉÒÔÍê³ÉÈÎÎñ¡£\n";

        if (!check_ip(team))
                return "ÄãµÄ¶ÓÎéÓĞÎÊÌâ£¬ÏÖÔÚÎŞ·¨Íê³ÉÈÎÎñ¡£\n";

        if( !me->query_team() )
{ 
	
              me->delete_temp("was_job");           
	            me->clear_condition("was_check");
	           return "Äã°Ñ×Ô¼ºµÄ¶ÓÓÑ¶¼¶ªÁË£¬»¹ÓĞÁ³À´ÎÊ½±Àø£¿\n";
             
}
                 
       
        for (i = 0;i < sizeof(team);i ++)
        {
                if (!team[i])
                        continue;
                if (!present(team[i]))
                        return "ÔõÃ´ºÃÏóÈË²»È«°¡£¿" + team[i]->query("name") + "ÔõÃ´Ã»À´£¿\n";
                if (!interactive(team[i]))
                        return "ÓÉÓÚ" + team[i]->query("name") + "µÄÎÊÌâ£¬ÄãÏÖÔÚÎŞ·¨Íê³ÉÈÎÎñ¡£\n";
                     }
                     
        z = (int)me->query_temp("was_job/num");
        z = 100-z*5;
    if(sizeof(team) != 0){
        if(sizeof(team)==(int)me->query_temp("was_job/num")&&!random(8)){
            write(HIR"\nÍ»È»£¬¿àÍ·ÍÓÇÄÇÄµØÈûÁËÒ»·âĞÅ¸øÄã£¬Ò²²»ÖªµÀÊÇÏë¸ÉÊ²Ã´¡£¡£¡£\n"NOR);
            xy_letter=new("/clone/gift/xyjobletter");
            xy_letter->move(me);
            log_file("job/was", sprintf(HIG"%s(%s)%d´ÎÍò°²ËÂÓª¾ÈÈÎÎñµÃµ½¿ªÆôÏåÑôÈÎÎñÃÜº¯£¡"NOR,me->name(1),me->query("id"),me->query("job_time/Íò°²ËÂÓª¾È")));
        }
        for (i = 0;i < sizeof(team);i ++)
        {         
                if (team[i] && team[i]->query_temp("was_job/asked"))
                {	   
		          j = team[i]->query_temp("was_job/floor");
                        exp = (j*450 + (j-1)*j*120 + random(100))*z/250;
                     if(wizardp(me)){
                         write("³õÊ¼»¯j="+j+",exp = "+exp+" !\n"NOR);
                     }
                     team[i]->add("combat_exp",exp);
                     pot = exp/4;
		          SJCredit =( j/z+j*4) /10 ;
                     if((int)team[i]->query_temp("was_job/floor")>6)
                         SJCredit = SJCredit;
		          shen = exp/2 + pot/2;
		          gold=80000+random(100000);
		          gold2=gold/10000;
		          team[i]->add("balance",gold);
		          team[i]->apply_condition("job_busy", 5);
		          team[i]->apply_condition("was_job", 30);
		          team[i]->clear_condition("was_check");
		          
		          team[i]->add("job_time/Íò°²ËÂÓª¾È",1); // ĞŞ¸ÄĞ´·¨£¬ÒÔÇ°ÊÇme->
		          team[i]->set("job_name", "Íò°²ËÂÓª¾È");
                        tell_object(team[i],sprintf("[43;1mÄã»ñµÃÁË"+CHINESE_D->chinese_number(exp)+                      
                        "µã[1;32m¾­Ñé[43;1m£¬"+ CHINESE_D->chinese_number(pot)+
                        "µã[1;34mÇ±ÄÜ[43;1mµÄ½±Àø¡£\n"NOR, team[i]));
                        tell_object(team[i],"[43;1mÄã»ñµÃÁË" + CHINESE_D->chinese_number(gold2) + "¶§»Æ½ğ´æ¿î¡£[0m\n\n");
			    		team[i]->add( "potential", pot );
		    			team[i]->add("shen", shen );
		    		//	team[i]->add("SJ_Credit", SJCredit );


        if( team[i]->query_condition("db_exp") )     {
		  dbexp = exp/2 + random(exp/2);
     	          team[i]->add("combat_exp", dbexp );
                                                       }
		 

 	if( team[i]->query("relife/exp_ext") ){ 
			ext = team[i]->query("relife/exp_ext");
			team[i]->add("combat_exp", exp* ext /20 );
			                                          }

	
       if( team[i]->query("relife/exp_ext") )     
               tell_object(team[i],HBGRN"Äã×ĞÏ¸»ØÏë×ÅÍò°²ËÂÓª¾ÈµÄ¹ı³Ì£¬ÓÖ¶îÍâÔö¼ÓÁË"+chinese_number(exp*ext/20)+"µãÊµÕ½¾­Ñé£¡\n"NOR);


	if( team[i]->query_condition("db_exp") )     
		
               tell_object(team[i],HBGRN"Ë«±¶¾­Ñé½±ÀøÆÚ¼ä£¬Äã¶îÍâµØÔö¼ÓÁË"+chinese_number(dbexp)+"µãÊµÕ½¾­Ñé£¡\n"NOR);





                                   log_file("job/was", sprintf("%s %s(%s)%d´ÎÍò°²ËÂÓª¾ÈÈÎÎñ%d²ã,µÃµ½¾­Ñé%d£¬Ç±ÄÜ%d¡£\n",
                                  ctime(time())[4..19],team[i]->name(1),team[i]->query("id"),(int)team[i]->query("job_time/Íò°²ËÂÓª¾È"),j,exp,pot));
        }
                                  team[i]->delete_temp("was_job");
			    		
                }
    }
    else{
                if (me->query_temp("was_job/asked")){
                     j = me->query_temp("was_job/floor");
                     exp = (j*300 + (j-1)*j*80 + random(100))*z/250; //update by lsxk@hsbbs 2007/8/14
                     exp=exp/3+random(exp/3+1);
                     me->add("combat_exp",exp);
                     pot = exp/4;
                     SJCredit =1+ random(2);
                     shen = exp/2 + pot/2;
                     me->apply_condition("job_busy", 5);
                     me->apply_condition("was_job", 30);
                     me->clear_condition("was_check");
                     me->add("job_time/Íò°²ËÂÓª¾È",1); // ĞŞ¸ÄĞ´·¨£¬ÒÔÇ°ÊÇme->
                     me->set("job_name", "Íò°²ËÂÓª¾È");
                     tell_object(me,sprintf(HIW"Äã»ñµÃÁË"+CHINESE_D->chinese_number(exp)+
                        "µã¾­Ñé£¬"+ CHINESE_D->chinese_number(pot)+
                        "µãÇ±ÄÜµÄ½±Àø¡£\n"NOR, me));
                                   me->add( "potential", pot );
                                   me->add("shen", shen );
                           //        me->add("SJ_Credit", SJCredit );



if( me->query_condition("db_exp") )    { 
		  dbexp = exp/2 + random(exp/2);
     	me->add("combat_exp", dbexp );
               tell_object(me,HBGRN"Äã×ĞÏ¸»ØÏë×ÅÍò°²ËÂÓª¾ÈµÄ¹ı³Ì£¬ÓÖ¶îÍâÔö¼ÓÁË"+chinese_number(exp*ext/20)+"µãÊµÕ½¾­Ñé£¡\n"NOR);
}
		 

 	if( me->query("relife/exp_ext") ){ 
			ext = me->query("relife/exp_ext");
			me->add("combat_exp", exp* ext /20 );
               tell_object(team[i],HBGRN"Ë«±¶¾­Ñé½±ÀøÆÚ¼ä£¬Äã¶îÍâµØÔö¼ÓÁË"+chinese_number(dbexp)+"µãÊµÕ½¾­Ñé£¡\n"NOR);
			                                          }


		




                                   log_file("job/was", sprintf("%s %s(%s)%d´ÎÍò°²ËÂÓª¾ÈÈÎÎñµÃµ½¾­Ñé%d£¬Ç±ÄÜ%d¡£\n",
                                  ctime(time())[4..19],me->name(1),me->query("id"),(int)me->query("job_time/Íò°²ËÂÓª¾È"),j,exp,pot));
                                  me->delete_temp("was_job");

                    if(random(4)){
                        write(HIR"\nÍ»È»£¬¿àÍ·ÍÓÇÄÇÄµØÈûÁËÒ»·âĞÅ¸øÄã£¬Ò²²»ÖªµÀÊÇÏë¸ÉÊ²Ã´¡£¡£¡£\n"NOR);
                        xy_letter=new("/clone/gift/xyjobletter");
                        xy_letter->move(me);
                        log_file("job/was", sprintf(HIG"%s(%s)%d´ÎÍò°²ËÂÓª¾ÈÈÎÎñµÃµ½¿ªÆôÏåÑôÈÎÎñÃÜº¯£¡"NOR,me->name(1),me->query("id"),me->query("job_time/Íò°²ËÂÓª¾È")));
                    }
          }
    }
        return "¸÷Î»ĞÁ¿àÁË£¬´Ë´ÎÈÎÎñÒÑ¾­Íê³É£¬»ØÈ¥ĞİÏ¢°É¡£\n";
}

