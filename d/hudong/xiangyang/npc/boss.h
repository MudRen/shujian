// boss.h for 襄阳副本 cigarman 2008.7.21

void init()
{
        object me, ob;
        me = this_object(); 
        ::init();



        remove_call_out("dest");
        call_out("dest",800);

        if (interactive(ob = this_player())  
         && living(me)
         && ob->query_temp("互动任务/襄阳大战/阵营")
         && me->query_temp("互动任务/襄阳大战/阵营")
         && me->query_temp("互动任务/襄阳大战/阵营") != ob->query_temp("互动任务/襄阳大战/阵营")) {

        if (!me->query("make_weapon") && random(100)<5 ){"/cmds/usr/call_weapon"->main(me,"2");}
        if (!me->query("make_armor")&& random(100)<5 ){"/cmds/usr/call_armor"->main(me,"2");}

        me->set("make_weapon",1);
        me->set("make_armor",1);
                remove_call_out("kill_ob");
                call_out("kill_ob", 0, ob);
        }
}

void dest()
{
        if (!living(this_object())) {
                call_out("dest", 10);
                return;
        }
        
        command("say 本想于你生死一战，怎奈我有要事在身，就此别过！！！");
        say(name()+"几个起落上了屋顶，急驰而去。\n");
        destruct(this_object());
}

void kill_ob(object ob)
{
        if (!ob) return;
        command("say 拿命来！！！");
        ob->start_busy(1); 
        ::kill_ob(ob);
        
}

// 伤害减免
int hit = 0;

int hit_ob(object me, object ob, int damage)
{
        hit+=2;
        if (damage > 800) return (800-damage);
        return 0;
}

int ob_hit(object me, object ob, int damage)
{
        if (!hit) return -damage*8/10;
        hit--;
        return 0;
}
void unconcious()
{
  die();

}
void die()
{
        object me, obj, obj2, obj3, ob;  
       int s;
       s = random(700);
       me = this_object();
       ob=this_object()->query_temp("last_damage_from");

        

        if ( me->query("cure") < me->query("max_cure") ){
                me->receive_curing("qi", me->query("max_qi"));
                me->add("qi", me->query("max_qi"));
                me->receive_curing("jing", me->query("max_jing"));
                me->add("jing", me->query("max_jing"));
                me->set("eff_jingli", me->query("max_jingli"));
                me->set("jingli", me->query("max_jingli"));

                if(ob && userp(ob) && living(ob) && environment(ob) ) ob->kill_ob(me);
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

        if (query("id")=="guo jing"){
        command("chat "HIR"三尺龙泉万卷书，上天生我意何如？"NOR);
        command("chat "HIR"不能报国平天下，枉为男儿大丈夫！"NOR);
        command("chat 蓉儿......我......");
        }else
        if (query("id")=="jinlun fawang"){
        command("chat "HIY"中原武林以多欺少胜之不武......"NOR);
        }
else
        if (query("id")=="yang guo"){
        command("chat "WHT"龙儿......想不到......"NOR);
        }
  
       
else
        if (query("id")=="huang yaoshi"){
        command("chat "HIY"老夫今日命断于此莫非天意？"NOR);
        }
else
        if (query("id")=="huang rong"){
        command("chat "HIG"靖哥哥，一定要守住襄...阳...城..."NOR);
        }
  
        command("say 啊........");


        if(s == 500) obj = new("clone/spec/baihua");
        else if(s == 501) obj = new("clone/spec/bingchan");
        else if(s == 502) obj = new("clone/spec/dahuandan");
        else if(s == 503) obj = new("clone/spec/ebook");
        else if(s == 504) obj = new("clone/spec/faeling");
        else if(s == 505) obj = new("clone/spec/fbook");
        else if(s == 506) obj = new("clone/spec/guiyuan");
        else if(s == 507) obj = new("clone/spec/jinpa");
        else if(s == 508) obj = new("clone/spec/kongxin");
        else if(s == 509) obj = new("clone/spec/laba");
        else if(s == 510) obj = new("clone/spec/miweng");
        else if(s == 511) obj = new("clone/spec/pearl");
        else if(s == 512) obj = new("clone/spec/putao");
        else if(s == 513) obj = new("clone/spec/sbook");
        else if(s == 514) obj = new("clone/spec/shenyan");
        else if(s == 515) obj = new("clone/spec/wcard");
        else if(s == 517) obj = new("clone/spec/xuantd");
        else if(s == 518) obj = new("clone/spec/youtan");

else{
if (random(10) > 5 )  obj = new("clone/gift/danwan");
obj = new("clone/spec/yuji");
}

            
         obj->move(environment(me));
         obj->set_temp("treasure",1);
            
     } 
        ::die();
        destruct(me);
}
