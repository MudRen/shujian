// boss.h for 襄阳副本 cigarman 2008.7.21

void init()
{
        object me, ob;
        me = this_object(); 
        ::init();

        if (interactive(ob = this_player())  
         && living(me)
         && !me->is_fighting()
         && ob->query_temp("互动任务/襄阳大战/阵营")
         && me->query_temp("互动任务/襄阳大战/阵营")
         && me->query_temp("互动任务/襄阳大战/阵营") != ob->query_temp("互动任务/襄阳大战/阵营")) {


        if (!me->query("make_weapon") && random(100)<2 ){"/cmds/usr/call_weapon"->main(me,"2");}
        if (!me->query("make_armor") && random(100)<2 ){"/cmds/usr/call_armor"->main(me,"2");}


                me->set("make_weapon",1);
                me->set("make_armor",1);


                me->set("combat_exp",ob->query("combat_exp"));

                me->set_leader(ob);
                me->kill_ob(ob);

           //     check_fight(me,ob); 

        }
}

void kill_ob(object ob)
{
        object me;
        me = this_object(); 
        if (!ob) return;
        command("say 拿命来！！！");
        ob->start_busy(1);
        ::kill_ob(ob);   
                        call_out("check_fight", 1, me, ob);     
}

void unconcious(){ die();}

void die()
{
       object me, obj, obj2, ob;  
       int s;

       s = random(100);
       me = this_object();
       ob=this_object()->query_temp("last_damage_from");
             
        if ( me->query("cure") < me->query("max_cure") ){
                me->receive_curing("qi", me->query("max_qi"));
                me->add("qi", me->query("max_qi"));
                me->receive_curing("jing", me->query("max_jing"));
                me->add("jing", me->query("max_jing"));
          
                me->set("eff_jingli", me->query("max_jingli"));
                me->set("jingli", me->query("max_jingli"));
//               if(ob && userp(ob) && living(ob) && environment(ob) ) ob->kill_ob(me);
                me->add("cure", 1);
                message_vision("$N深深吸了几口气，脸色看起来好多了。\n",me);
                me->start_busy(1);
                return;
        }

        if( me->query("cure") >= 5 
          && objectp(ob) 
          && userp(ob) 
          && living(ob) 
          && ob->query_temp("互动任务/襄阳大战/阵营")
          && me->query_temp("互动任务/襄阳大战/阵营")
          && me->query_temp("互动任务/襄阳大战/阵营") != ob->query_temp("互动任务/襄阳大战/阵营")){ 
          command("say 啊........");
        
       if (!random(3)){
          obj = new("clone/gift/danwan");          
          obj->move(environment(me));
          obj->set_temp("treasure",1);
          }
        } 
          ::die();
          destruct(obj); 
}
void check_fight(object me,object ob) 
{


        if( !me|| !ob ) return;
        if( !ob->query_temp("互动任务") ) {
              command("say 结束了还打？没时间和你磨蹭。拜拜！！");
              me->start_busy(-1);        
              me->remove_all_enemy();
              me->delete_temp("kill_other");
              me->delete_temp("other_kill");
              ob->remove_all_enemy();
              ob->delete_temp("kill_other");
              ob->delete_temp("other_kill");
              return;
        }
          else 

          call_out("check_fight", 1, me, ob);
          return;
}                       

