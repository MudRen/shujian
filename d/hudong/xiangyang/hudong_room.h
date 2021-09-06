#include <ansi.h>
mapping skills;
string *sk;
int i;

void init(object me)
{
        object ob;

        mapping smap, pmap;   //很重要防止生成npc 没有武功问题 cigarman
            
        /*根据时间判断玩家所在场景look时的文字描述*/
        add_action("do_look", "look");

        /*当玩家身处玄武门的时候可以使用开(kai)城门命令,若打开城门后，地图随机的反方npc随机增加
          初始的地图正反双方npc是2M，一旦打开城门后，在传送的npc经验就是反方参战玩家经验最高的copy*/
      add_action("do_kai", "kai"); 

       me = this_player();

       if( userp(me) && me->query_temp("互动任务/襄阳大战/阵营") && random(100) > 97 ) {
                   ob=new(__DIR__"npc/killer");
                  // ob->setparty(1,me->query("max_pot")-100,me->query("combat_exp"));
                   ob->set("combat_exp",me->query("combat_exp"));
                   ob->reincarnate();

                    skills = ob->query_skills();
                if (mapp(skills)) 
                {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                        skills[sk[i]] = this_player()->query("max_pot")-100;
                }
                  

                smap = ob->query_skill_map();
                pmap = ob->query_skill_prepare();
              if ( sizeof(smap ) && sizeof(pmap ) ){

                ob->move(environment(me));
                
                if(random(100) > 50) {
                ob->set("title",HIY"大宋义士"NOR); 
                ob->set_temp("互动任务/襄阳大战/阵营",1);
                }
                else{
                 ob->set("title",HIR"蒙古先锋"NOR); 
                 ob->set_temp("互动任务/襄阳大战/阵营",2);
                }
//                me->start_busy(1); 
                message_vision(CYN"$N突然打了个冷颤，总觉得背后生风。\n"NOR,me);
              }
                 else
                 destruct(ob);
      
        }
}

int do_look()
{
        object me = this_player();
        mixed *local;
        local = localtime(time() * 60);
        if(local[2] < 4 || local[2] >= 21) //晚上9点到凌晨4点
        {
                write(BLU"    战斗持续了一夜，进攻气势稍歇，城里陷入了一片死寂之中，偶尔只能听\n"
                         "见猫头鹰夜枭般的叫声，天上没有月亮，借着暗淡的"HIW"星光"BLU"，被火熏得漆黑的断\n"
                         "壁残垣隐约可见，这黑暗中竟似隐藏着无限杀机，让人不由得战战兢兢不敢发\n"
                         "出一丝一毫的声音。\n"NOR, me);
        }
        if(local[2] >= 4 && local[2] < 8) //凌晨4点到早上8点
        {               
                write(CYN"    震天的喊杀声、进攻的锣鼓声、兵器的磕击声响了一夜。天色渐渐亮了起\n"
                         "来，街道上小巷里甚至院子里躺满了横七竖八的尸体，鲜血在地上漫无目的地\n"
                         "流淌，逐渐汇成了一条"HIR"红色"CYN"的溪流，掺杂着青草芬芳的空气中弥漫着血腥的味\n"
                         "道。不远处三三两两的双方士兵兀自狠斗、不肯罢手。\n"NOR, me);
                        
        }
        if(local[2] >= 8 && local[2] <= 13) //早上8点到下午1点
        {
                write(HIG"    这里已经没有了大战前的样貌，城中百姓已经疏散到了安全地方，空气中\n"
                         "弥漫着烧焦的味道，比比皆是正激烈厮杀的人，地上满是"HIR"鲜血淋漓"HIG"的残肢尸体\n"
                         "让人看了无不心惊胆颤，兵器相交声，喊杀声，惨叫声布满整个襄阳城。\n"NOR, me);
        }
        if(local[2] > 13 && local[2] < 16) // 下午1点到下午4点
        {
                write(HIC"    阳光洒向整个襄阳城，放眼望去战火的硝烟依然没有散去的意思，双方的\n"
                         "喊杀声震天动地，其中还夹杂着兵器敲击声，以及熊熊火焰不时发出的爆裂声\n"
                         "猛然听见号角长鸣，看来又一次大举进攻开始了。\n"NOR, me);
        }
        if(local[2] >= 16 && local[2] < 21) //下午4点到晚上9点
        {
                write(HIB"    襄阳自古就是兵家必争之地，时至今日也不例外，蒙古大军骁勇善战，大\n"
                         "宋义士誓死守城，双方你进我退，往来交错，孰强孰弱却也难分清，血腥气味\n"
                         "加上横尸遍地的情景，让人心情不住的亢奋着。\n"NOR, me);
        }
}

int do_kai(string arg)
{
        object me = this_player();
        object ob = new("/d/hudong/xiangyang/npc/killer");
        object room;
         
        if(arg != "城门") return notify_fail("你要打开什么？\n");
          
        if(!objectp(present("dasong yishi", environment(me)))&&objectp(room=load_object("/d/hudong/xiangyang/xuanwumen"))){
           ob->move(room);
           tell_object(me, HIY"你飞身跳到城门边想要打开城门，不料身后一人大喊住手....\n"NOR);
           COMBAT_D->auto_fight(ob, me, "aggressive");
          return 1;
          } 
           return notify_fail("你四周全是敌人哪有时间开城门？\n");
           
          
     
}

int valid_leave(object me, string dir)
{     
        if( userp(me) && !me->query_temp("互动任务")){
        tell_object(me,"非法进入副本，系统自动请出。\n");
        me->move("/d/city/guangchang");
       me->delete_temp("title");
       me->remove_all_killer();
       me->dismiss_team();
       me->clear_conditions_by_type("poison");
       me->clear_conditions_by_type("hurt");
       me->clear_conditions_by_type("busy");
       me->clear_condition("killer"); 
       me->delete_temp("kill_other");
       me->delete_temp("other_kill");
       me->clear_condition("job_busy");
        return notify_fail("");
        }
         return ::valid_leave(me, dir);
}

