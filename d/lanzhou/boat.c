// �����Ӷɴ�

#define SHIP __DIR__"boat"

inherit ROOM;
void create()
{
	set("short", "�ƺӶɴ�");
	set("long", @LONG
�ƺ��ϵĶɴ��������ֺܼ�ª��С�ۡ�һλ������������վ�ڴ�β����
���ƶ棬һλ����׳˶��С����Ҳ�ڴ�ͷ�þ��ػ�ˮ�Ŵ���
LONG );

        set("no_fight", "1");
        set("no_sleep_room", 1); 
        set("side", "road3");

	set("outdoors", "����");
	setup();
}

int arrive(string arg)
{
	object room, ob;
     
	ob = this_object();

	if(!ob->query("start")) ob->set("start", 1);
	if(!(string)ob->query("side")) set("side", "road3");
	if(stringp(arg)) set("side", arg);
	if(!(room = find_object(__DIR__+ob->query("side"))))
		room = load_object(__DIR__+ob->query("side"));
	if(room = find_object(__DIR__+ob->query("side"))){
		ob->set("exits/out", __DIR__+ob->query("side"));
		room->set("exits/enter", SHIP);
		message("vision", "\n�ɴ��͵�һ���Ѿ�����������˵������������´��ɣ���\n", ob);
		message("vision", "˵�Ž�һ��̤�Ű���ϵ̰����γ�һ����ȥ(out)�Ľ��ݡ�\n", ob);        
		message("vision", "\nһ�Ҷɴ�������ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿�����(enter)��\n", room);
		remove_call_out("on_board");
		call_out("on_board", 20);
	}
	return 1;
}

void on_board()
{
	object room, *obj, ob;
        int i;
        
        ob = this_object();
        
        if( !query("exits/out") ) return;

        if( room = find_object(__DIR__+ob->query("side")) ){
                obj = all_inventory(ob);
                for(i = 0; i < sizeof(obj); i++) {
                        if (userp(obj[i]) && obj[i]->query_temp("side") != ob->query("side")) {
                                if (!living(obj[i])) message_vision("������$Ņ���˴���\n", obj[i]);
                                obj[i]->move(room);
                                obj[i]->delete_temp("side");
                                if (!living(obj[i])) tell_room(room, obj[i]->name() + "��̧���˴���\n", ({obj[i]}));
                                else tell_room(room, obj[i]->name() + "�����˴���\n", ({obj[i]}));
                        }
                }
                room->delete("exits/enter");
                message("vision", "\n�����ǰ�̤�Ű���������������һ�㣬�ɴ������ʻȥ��\n", this_object());
                message("vision", "\n�����ǰ�̤�Ű���������˵��һ��������ඡ�������һ�㣬�ɴ������ʻȥ��\n", room);
                }
        delete("exits/out");
        if(ob->query("side") == "road3") ob->set("side", "road2");
        else ob->set("side", "road3");
        remove_call_out("arrive");
        call_out("arrive", 10+random(10));
}
