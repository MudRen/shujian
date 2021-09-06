// yanshi.c ��ʯ
// snowman 16.12.98
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
string sea();
void create()
{
	set("short", HIW"��ʯ"NOR);
	set("long", @LONG
����һ��¶��ˮ�����ʯ�������ǻ�������ΧһƬ���̣�ԭ��������һ��
����ĵ��졣�����������Ǽ�ʯ��᾵�ɽ�壬�濪������Ī����״������ȴ��
һƬ��������ͷ��ƽҰ���˻�ɽ������󺣶��ɡ��˴��䴦����������ɽ����
���𣬵��������ͳ���ɽ��������һ�����ơ�����������һɽ����һɽ����
��ñ�����̡���������һƬƬ����Ұ����ʯ���ϲ��Ǻ���(sea�����м��鸡��
������Ư������������һ�����̡�
LONG);
        set("item_desc", ([
		"sea" : (: sea :),
        ]) );
	set("exits",([
		"north" : __DIR__"pingyan1",
	]));
	set("objects",([
		"/d/mingjiao/obj/luopan": 1,
	]));
	set("outdoors", "����");
	setup();
}

void init()
{
     if(!this_player()->query_condition("cold_wind") && !wizardp(this_player()))
        this_player()->apply_condition("cold_wind", 1);
	add_action("do_make","make");
        add_action("do_push","tui");
        add_action("do_enter","enter");
}

int do_enter()
{
        object me, sea, *inv;
        int i;
        me = this_player();

        if(!query("boat_on_sea")) return 0;
        if(!(sea = find_object("/clone/misc/sea")))
             sea = load_object("/clone/misc/sea");
        if(sea = find_object("/clone/misc/sea")){
             inv = all_inventory(sea);
             for(i= 0;i< sizeof(inv);i++){
                   if(inv[i]->query("boat_of") == base_name(this_object())){
                          message_vision("$N�����һ���ĵ��ϸߣ����¾ʹ����˷�����\n\n", me);
                          me->move(inv[i]);
                          message("vision",me->name()+"�����һ������������\n",environment(me), ({me}) );
                          return 1;
                   }
             }
        }
        else write("sea boat error, please call wizard. \n");
        return 1;
}

int do_push(string arg)
{
        object me, ob;
        me = this_player();

        if(!query("boat")) return notify_fail("��ʲô��\n");
        if( arg=="chuan" || arg=="��" ) {
            if(me->is_busy()) return notify_fail("����æ���ء�\n");
            if(query("boat_on_sea")) return notify_fail("�������ҷ����أ���������ȥһ�ң����ǻ���ײ�ġ�\n");
            me->start_busy(5);
            add("boat", -1);
            message_vision("$Nʹ�����̵ľ������������Ƴɵķ����ƽ��˴󺣡�\n\n", me);
            EMOTE_D->do_emote(me,"touch", me->query("id"));
            me->add("jingli", -50);
            ob=new("/clone/misc/boat");
            ob->set("boat_of", base_name(this_object()));
            ob->set_temp("stepe", 200);
            ob->set_temp("stepn", 945);
            ob->move("/clone/misc/sea");
            set("boat_on_sea", 1);
            return 1;
        }
}

int do_make(string arg)
{
        object me, ob, weapon;
        int i;
        string msg;
        me = this_player();
        weapon = me->query_temp("weapon");
        i = query("make_times");

        if( arg=="chuan" || arg=="��" ) {
            if(me->is_busy()) return notify_fail("����æ���ء�\n");
            me->start_busy(5);
            if(!objectp(ob = present("shu gan", environment(me)))
               && !objectp(ob = present("shu gan", me)))
                     return notify_fail("��Ҫ��ʲô�����촬��\n");
            switch(i){
                case 0: if(!weapon || weapon->query("flag")!=4) return notify_fail("����Ҫһ�������Ĺ��ߣ������ʿ����ɡ�\n");
                        msg = "$N�������ʿ������ţ������������������ε�������\n";
                        add("make_times", 1); break;
                case 1: msg = "$N�������ϵ���Ƥ������������������������������˷���\n";
                        add("make_times", 1); break;
                case 2: msg = "$N�������Ϳգ���ĥ��һ����Ȼ�����ͳ���ľͷ�����˽�������þߡ�\n";
                        add("make_times", 1); break;
                case 3: msg = "$N��һ��������Բ��ϸ����ϸ���˳ߴ磬��������Φ�ˡ�\n";
                        add("make_times", 1); break;
                case 4: msg = "$N����֧���ּӹ�����Φ��һ���������������ˡ�\n";
                        delete("make_times");
                        add("boat", 1);
                        break;
                default: break;
            }
            me->add("jingli", -100);
            destruct(ob);
            message_vision(msg, me);
            return 1;
        }
        else return notify_fail("��Ҫ��ʲô��\n");
}

string sea()
{
       string msg;
       int boat;
       boat=query("boat_on_sea");

       msg = "\n����һƬ����һ���޼ʣ������������ĸ�����\n";
       if(boat)
          msg += "����ͣ����һֻ��ª�ķ��������沨����ҡ����������Ϳ�����ȥ(enter)��\n";
          msg += "�������ƽ̹�����������Ǹ��ܺõĹ�����\n";
       if(query("make_times") >= 1){
            if(query("make_times") >= 4) msg += "��һֻ�þ��������Ƴɵļ�ª�����Ĵ��壬�����ǿ�Ҫ����ˡ�\n";
            else msg += "һ�Է��м������������ɣ��Ѿ����ʿ��������롣\n";
       }
       if(query("boat")) msg += "���߷����þ��������Ƴɵļ�ª���������ʹ���ƣ����԰�����(tui)��ˮȥ��\n";
       return msg;
}
