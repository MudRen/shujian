//����ϵͳ֮��Ǯƪ
#include <ansi.h>
#include <get_place.h>

inherit ITEM;
int check(object ob);

string *no_kill_list = ({
         "mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});


void create()
{
    set_name(HIW "����" NOR, ({ "jin he","he","jinhe"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
                        "һ��̴ľ���ɵĹ����ɫ��С���ӡ�\n"
                        "����Լ��(jiancha)��������������ʲô���ܡ�\n"
                        );
                set("no_sell", "�ҵ��졭�㡭��֪������ɶô������Ҳ����������");
                set("material", "wood");
                set("cloned",0);
                set("no_give",1);
                set("viewed",0);
             }
        setup();
}

void init()
{

        object *living;
        object target, objwhere;
        string str;
        int i,j;
        
        if(!query("cloned")){
        living = livings();
        for (i=0;i < sizeof(living);i++){
                j = random(sizeof(living));
                if (!j || j == sizeof(living) -1) continue;
                if(check(living[j]) ){
                        target = living[j];
                        objwhere = environment(target);
                        str = objwhere->query("short");
                        if (!sizeof(objwhere->query("exits"))
                        || str == "��ɮ��" 
                        || str == HIR"������"NOR
                        || str == "��շ�ħȦ" ) continue;
                        if( get_place(base_name(environment(target)))!="" ) break;
                }
        } 
        
        set("cwheredig",get_place(base_name(environment(target)))+environment(target)->query("short"));
        set("wheredig",base_name(environment(target)));
        set("cloned",1);
        }
        add_action("do_dig", "dig");
        add_action("do_dig", "search");
        add_action("do_jiancha", "jiancha");
}

int do_jiancha(string arg)
{
        object me=this_player();
        object ob=this_object();
        string bzhere;
        if(arg!="����" && arg!="jing he" && arg!="he" && arg!="jinhe") return notify_fail("��Ҫ���ʲô��\n");
        
        if(!query("viewed")) //����Ʒ��û�б����
        {
                
                if(me->query("id")!=query("gift_target")){//����õ����Ǳ��˵ĺ���
                        message_vision("$N�ֽŽ�Ӳ�ĸ����һ�����С�\n", me);
                        if (random(me->query("kar")) > 10 && random(100) < 50){
                        message_vision("$N��������������������һ�����أ�,\"ž\"��һ�������ӵļв���˿�����\n", me);
                        bzhere=ob->query("cwheredig");
                        set("viewed",1);
                        set("long","һ��̴ľ���ɵĹ����ɫ��С���ӣ�����ļв��Ѿ��򿪡�\n"
                                           "һ�ŷ��Ƶ�ֽ����д��ģ���ļ�����:\n"
                                           "���ݺὭ��ʱ����"+HIY+bzhere+NOR+"����Щ�����£�����Ե��ǰȥ�ھ�(dig)��\n");

                        return notify_fail( "һ�ŷ��Ƶ�ֽ����д��ģ���ļ�����:\n"
                                           "���ݺὭ��ʱ����"+HIY+bzhere+NOR+"����Щ�����£�����Ե��ǰȥ�ھ�(dig)��\n");
                        }
                }
                else{
                message_vision("$N�������ź��ӣ����ҳ�������ʲô���ܡ�\n", me);
                if(random (100) > 50)//�Ǳ��˵ĺ���
                {
                        message_vision("$N������ᣬ������·���ڰ�ť��һ�������ӵļв���˿�����\n", me);
                        bzhere=ob->query("cwheredig");
                        set("viewed",1);
                        set("long","һ��̴ľ���ɵĹ����ɫ��С���ӣ�����ļв��Ѿ��򿪡�\n"
                                           "һ�ŷ��Ƶ�ֽ����д��ģ���ļ�����:\n"
                                           "���ݺὭ��ʱ����"+HIY+bzhere+NOR+"����Щ�����£�����Ե��ǰȥ�ھ�(dig)��\n");
                        return notify_fail( "һ�ŷ��Ƶ�ֽ����д��ģ���ļ�����:\n"
                                           "���ݺὭ��ʱ����"+HIY+bzhere+NOR+"����Щ�����£�����Ե��ǰȥ�ھ�(dig)��\n");
                } 
                }
                return notify_fail("�㿴�˰��죬Ҳû����������ӵ�������ô���¡�\n");                                       
        }
        return notify_fail("���ӵļв��Ѿ��򿪣��������ϸ�����ӣ�look jinhe��Ȼ���ȡ��Ӧ�ж���\n");
}

int do_dig(string arg)
{
        object me=this_player();
        object ob=this_object();
        int bound;
        object money, book, letter;

        if(me->is_fighting()) return notify_fail("ս���л�Ҫ�ڣ���������������\n");
        //if(arg!="����" && arg!="baozang" && arg!="caibao" && arg!="here") return 0;
        if(base_name(environment(me))!=ob->query("wheredig")) return 0;
                             
        
        if(random(me->query("kar")<15)) return 0;
        
       if( random(30 ) > 25) {
                message_vision(HIG"$NͻȻ�ڵ�һ���ź���������Լ�л��ܵ�������\n"NOR,me);
                message_vision(HIG"$N�о���������������ɵ�����飬�ƺ�Ӧ�����ż��ͳ�ȥ��\n"NOR,me);
                 CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s���һ��"+HIY+"���ܾ���"+HIM+"��", me->name(1)));
                letter = new("/clone/gift/xyjobletter");
                letter->move(me);
                log_file("job/PRIZE", sprintf("%8s%s��ÿ�����������ս�Ľ�����\n", ctime(time())[4..19],
                me->name(1)+"("+me->query("id")+")")  );
                destruct(this_object());
                return 1;       
                
        } 
        if(random(100) == 0 && me->query("zhou/fail") > 1) {
                message_vision(HIG"$NͻȻ�ڵ�һ�Ѳоɵ��鼮������д��һЩϡ��Źֵķ��š�\n"NOR,me);
                message_vision(HIG"$N�����˸о���Ȼ���ʣ��о��Լ�������澭�ֽ���һ����\n"NOR,me);
                me->add("zhou/fail",-1);
                 CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s���һ�����½�"+HIY+"����"+HIM+"�Ļ��ᣡ", me->name(1)));
                log_file("job/PRIZE", sprintf("%8s%s������½�����ϵĽ�����\n", ctime(time())[4..19],
                me->name(1)+"("+me->query("id")+")")  );
               	destruct(this_object());
               	return 1;       
                
        }      
        if(random(100) == 0 && me->query("zhou/failed") > 1) {
                message_vision(HIG"$NͻȻ�ڵ�һЩϡ��ŹֵĶ������о��Լ��ֱ���ɵ��\n"NOR,me);
                message_vision(HIG"$NͻȻ�Լ������Լ�������ô����Ϊʲô��ȥ������ͨ��Ҳ�������ڸı���ҵĿ������أ���\n"NOR,me);
                me->add("zhou/failed",-1);
                CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s���һ�����½�"+HIY+"����"+HIM+"�Ļ��ᣡ", me->name(1)));
                log_file("job/PRIZE", sprintf("%8s%s������½⻥���Ľ�����\n", ctime(time())[4..19],
                me->name(1)+"("+me->query("id")+")")  );
                destruct(this_object());
                return 1;       
                
        }       
        if(random(100) > 90) {
                book = new("/clone/gift/book");
               	book->set("gift_target",me->query("id"));
               	book->move(me);
               	message_vision(CYN"$N��ͣ����������ѽ�ڡ�\n"NOR,me);
                message_vision(CYN"$NͻȻ�ڵ�һ��"+book->query("name")+"��\n"NOR,me);
                message_vision(CYN"$N�����˲�ע�⣬�Ͻ���"+book->query("name")+CYN+"�������������뻳�\n"NOR,me);  
                CHANNEL_D->do_channel( this_object(), "rumor",sprintf("��˵%s��%s�ҵ���һ%s%s��", me->name(1),query("cwheredig"),
                book->query("unit"),book->query("name")));            
                destruct(this_object());
                return 1;       
                
        }                        
        if (random(100) > 20){
                switch(random(4))
                {
                case 0:
                        money=new("/clone/money/gold");
                        bound=random(10) + 20;
                        break;
                case 1:
                        money=new("/clone/money/thousand-cash");
                        bound=random(10)+5;
                        break;
                case 2:
                        money=new("/clone/money/gold");
                        bound=random(10) + 20;
                        break;
                case 3:
                        money=new("/clone/money/thousand-cash");
                        bound=random(10) + 3;
                        break;
                default:

                }
        
        message_vision("$NͻȻ����\"��\"��һ���������õ���ʲô������\n",me);
        message_vision("���϶���һ������߰ߵ������ӣ�$N���˲�ע�⣬Ѹ�ٰ����д��뻳�С�\n",me);
        message_vision("$N�����������ó���һЩ" + money->name(1) + "��\n",me);
        message_vision("$N�����������ó���һЩ�齣ͨ�������²��ɵô�ϲ ��\n",me);
        money->set_amount(bound);
        money->move(me);
        me->add("SJ_Credit",2+random(2) );
        destruct(this_object());
        return 1;       
        }
        else{
        message_vision("$N���������������ʲô������\n",me);
        return 0;
        
        }
}


int check(object ob)
{
        object room;
        string room_name;
        
        if(!objectp(ob)
         || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
         || ob->query("env/invisibility")
         || ob->query("no_quest")
         || member_array(ob->query("id"), no_kill_list) != -1
         || userp(ob)
         || ob->query("attitude")=="aggressive"
         || ob->query("have_master")
         || !objectp(room=environment(ob))
         || room->query("no_fight") 
         || room->query("outdoors") == "���ش��"
         || strsrch(room_name = file_name(room),"/d/") != 0
         || strsrch(room_name, "/d/wizard/") == 0
         || strsrch(room_name, "/d/wuguan/") == 0
         || strsrch(room_name, "/d/death/") == 0
         || strsrch(room_name, "/d/kunlun/") == 0
         || strsrch(room_name, "/d/mingjiao/lsd/") == 0
         || strsrch(room_name, "/d/mingjiao/bhd/") == 0
         || strsrch(room_name, "/d/wudang/") == 0
         || strsrch(room_name, "/d/shaolin/liwu") == 0
         || strsrch(room_name, "/d/shaolin/houyuan") == 0
         || strsrch(room_name, "/d/huashan/jiabi") == 0
         || strsrch(room_name, "/d/shaolin/fumoquan") == 0
         || strsrch(room_name, "/d/shaolin/xinchan") == 0
         || strsrch(room_name, "/d/mingjiao/yuanzi") == 0
         || strsrch(room_name, "/d/mingjiao/wxiang") == 0
         || strsrch(room_name, "/d/baituo/") == 0
         || strsrch(room_name, "/d/thd/") == 0
         || strsrch(room_name, "/d/sld/") == 0) 
         return 0;
        return 1;
}
