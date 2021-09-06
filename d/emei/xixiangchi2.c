// Room: /d/emei/xixiangchi.c

inherit ROOM;
#include <ansi.h>
#include <command.h>
string look_chi();

void create()
{
        set("short",HIW "ϴ��ر�" NOR);
        set("long", @LONG
ϴ���ԭֻ��һͤ��ͤǰ��һ��ʯ����С��(pool)���ر߲�Զ����Σ�ҡ�
ϴ���Ԣ��һƬ��ɼ���У��������������ɽ������������������̿���
���������ʱ�����������ţ�������ޣ����������칬����������������
�������ġ����ҹ�¡���
LONG
        );
        set("outdoors", "����ɽ");
        set("item_desc",([          
            "pool" : (: look_chi :),
        ]));
        set("exits", ([ 
          "south" : __DIR__"xixiangchi",
          ]));

        setup();
}

void init()
{
        add_action("do_jump", "xi");
        add_action("do_halt", "halt");
}

int do_halt(string arg)
{
        object me = this_player();

        if (!me->is_busy() && !me->is_fighting())
                me->add_busy(2);
        return 0;
}

int do_jump(string arg)
{
        int i, j;
        object me, room, *ob, *inv;
        me = this_player();
        if ( me->query("gender") == "����" ) {
            tell_object(me, "��һ������ү������Щ�����ʲô��\n");
            return 1;
        }
        if (!(room = find_object(__DIR__"chi2")))
              room = load_object(__DIR__"chi2");
        ob = all_inventory(room);
        j = sizeof(ob);

     if(!living(me) ) return 0;
     if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

     if( !arg || arg == "" || arg != "pool" )
        return notify_fail("��Ҫ��ʲô��\n");
        
     if((me->query_encumbrance()*20) > me->query_max_encumbrance())
        return notify_fail("�����ϵĶ���̫���ˣ�\n");

     inv = all_inventory(me);
       for (i = 0; i < sizeof(inv); i++){
               if(!inv[i]->query("no_drop"))
                  DROP_CMD->do_drop(me, inv[i]);
               else if(inv[i]->query("equipped"))
                   inv[i]->unequip();
               else
                  tell_object(me, "�㽫"+inv[i]->name()+"��������ϸ���á�\n");         
                }

        tell_object(me, GRN "���ߵ��رߣ���ȥ�����Ҫ����ϴ��ء�\n"NOR);
        tell_room(environment(me), me->name()+"ת���ߵ��رߣ�������Ҫ����������ˮȥ��\n", ({ me }));
       if(j>0){
                if(j>1) {
                        write(HIR"��ͻȻ���ֳ�ˮ�����ˣ����һ���ֹһ��������æ���˻�����\n"NOR);
                        return 1;
                }
                tell_object(me, "��ͻȻ���ֳ�ˮ�����ˣ�\n");
                for(i=0; i<sizeof(ob); i++) {
                        if(!living(ob[i])) continue;
                        if(me->query("gender") == ob[i]->query("gender")){
                                if(me->query("gender") == "Ů��")
                                        tell_object(me, "����һ����ԭ��Ҳ�Ǹ�Ů�ӡ�������һЦ����������ˮȥ��\n");
                                if(me->query("gender") != "Ů��")
                                        tell_object(me, "����һ�����Է�����Ů�ӡ�������̾�˿�������������ˮȥ��\n");
                                me->move(__DIR__"chi2");
                        } else {
                                tell_object(me, "����һ����ԭ���Է���λ��������������һ�죬��æ�����·����˻�����\n");
                                tell_room(environment(me), me->name()+"ת���ߵ��رߣ�����һ�٣������˻�����\n", ({ me })); 
                        }
                }
                return 1; 
        } 
        me->move(__DIR__"chi2");
        return 1;
}

void kan_pool(object me, object room)
{
    int i, j;
    object *ob;

        if (!me || !room)
                return;
    ob = all_inventory(room);
     j = sizeof(ob);
    if (j>0){
        if (me->query("gender") == "Ů��")
            return;
        tell_object(me, HIY "������ֳ���������������ˮ����ԶԶ������ģ����ѩ�ױ�Ӱ���������ˡ�����\n"NOR);
        if (!wizardp(me))
                tell_room(environment(me), HIY +me->name()+"ͻȻ���۷�ֱ���Ŵ��˿ڣ���ˮ��વ��ֱ��������\n"NOR, ({ me }));
        for(i=0; i<sizeof(ob); i++) {
          if(!living(ob[i])) continue;
          tell_object(ob[i], HIR"\n�㲻����һ��ͷ���������˹�������ڳر�͵����\n"NOR);
          ob[i]->set_temp("looked", 1);
          if(ob[i]->query("gender") == "Ů��"){
             tell_object(ob[i], HIR"��Ѫ���ϳ壬��ʱ�е�һ�����Σ�\n"NOR);           
            if(ob[i]->query("jing")>=100)
                ob[i]->add("jing",-100);
         else
             ob[i]->unconcious();
          ob[i]->set_temp("apply/short", ({ob[i]->name()+"("+ob[i]->query("id")+")"HIR" <ȫ��> "NOR}));       
         } else{
          tell_object(ob[i], "\n���䲻��Ϊ�⣬���Ѿ�û����Ȥ�ټ�����ˮ�ˡ�\n");
          ob[i]->force_me("halt");     
          }
        }
     return;
     }
   return;
}

string look_chi()
{
    object me, room;
    me = this_player();
    if (!(room = find_object(__DIR__"chi2")))
          room = load_object(__DIR__"chi2");

        if (me->is_busy())
                return "����æ���ء�\n";
        if (!wizardp(me)) {
                message_vision("$N����ת���رߣ��쳤������������ȥ��\n", me);
                me->start_busy(30);
        }
        "/cmds/std/look.c"->look_room(this_player(), room);
        remove_call_out("kan_pool");
        call_out("kan_pool", 1, me, room); 
        return "";
}

int valid_leave(object me, string dir)
{
 if (dir == "southup" && (int)me->query_skill("dodge", 1) < 101 ) {
      me->improve_skill("dodge",(int)me->query("dex"));
      me->receive_damage("jingli",  (int)me->query("dex"));
      return 1; 
      }     
      return ::valid_leave(me, dir);
}