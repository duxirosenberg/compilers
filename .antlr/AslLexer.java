// Generated from /home/drosenberg/University/UPC Exchange Semester/CL-lab/practica/asl/Asl.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AslLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, ASSIGN=3, PLUS=4, SUB=5, MUL=6, DIV=7, MOD=8, VAR=9, INT=10, 
		FLOAT=11, CHAR=12, BOOL=13, EQ=14, NEQ=15, G=16, GE=17, L=18, LE=19, AND=20, 
		NOT=21, OR=22, INTVAL=23, FLOATVAL=24, BOOLVAL=25, CHARVAL=26, IF=27, 
		THEN=28, ELSE=29, ENDIF=30, FUNC=31, ENDFUNC=32, READ=33, WRITE=34, WHILE=35, 
		DO=36, ENDWHILE=37, RETURN=38, ID=39, STRING=40, COMMENT=41, WS=42, LPAR=43, 
		RPAR=44, SEMICOLON=45, COLON=46, COMMA=47;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", "VAR", 
			"INT", "FLOAT", "CHAR", "BOOL", "EQ", "NEQ", "G", "GE", "L", "LE", "AND", 
			"NOT", "OR", "INTVAL", "FLOATVAL", "BOOLVAL", "CHARVAL", "IF", "THEN", 
			"ELSE", "ENDIF", "FUNC", "ENDFUNC", "READ", "WRITE", "WHILE", "DO", "ENDWHILE", 
			"RETURN", "ID", "STRING", "ESC_SEQ", "COMMENT", "WS", "LPAR", "RPAR", 
			"SEMICOLON", "COLON", "COMMA"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'['", "']'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'var'", 
			"'int'", "'float'", "'char'", "'bool'", "'=='", "'!='", "'>'", "'>='", 
			"'<'", "'<='", "'and'", "'not'", "'or'", null, null, null, null, "'if'", 
			"'then'", "'else'", "'endif'", "'func'", "'endfunc'", "'read'", "'write'", 
			"'while'", "'do'", "'endwhile'", "'return'", null, null, null, null, 
			"'('", "')'", "';'", "':'", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", "VAR", 
			"INT", "FLOAT", "CHAR", "BOOL", "EQ", "NEQ", "G", "GE", "L", "LE", "AND", 
			"NOT", "OR", "INTVAL", "FLOATVAL", "BOOLVAL", "CHARVAL", "IF", "THEN", 
			"ELSE", "ENDIF", "FUNC", "ENDFUNC", "READ", "WRITE", "WHILE", "DO", "ENDWHILE", 
			"RETURN", "ID", "STRING", "COMMENT", "WS", "LPAR", "RPAR", "SEMICOLON", 
			"COLON", "COMMA"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public AslLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Asl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\61\u013e\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\3\2\3\2\3\3\3\3\3\4\3\4"+
		"\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\n\3\n\3\13\3\13\3\13"+
		"\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16"+
		"\3\16\3\17\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3\22\3\22\3\22\3\23\3\23"+
		"\3\24\3\24\3\24\3\25\3\25\3\25\3\25\3\26\3\26\3\26\3\26\3\27\3\27\3\27"+
		"\3\30\6\30\u00a8\n\30\r\30\16\30\u00a9\3\31\6\31\u00ad\n\31\r\31\16\31"+
		"\u00ae\3\31\3\31\6\31\u00b3\n\31\r\31\16\31\u00b4\3\32\3\32\3\32\3\32"+
		"\3\32\3\32\3\32\3\32\3\32\5\32\u00c0\n\32\3\33\3\33\3\33\3\33\3\34\3\34"+
		"\3\34\3\35\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37"+
		"\3\37\3\37\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3!\3!\3\"\3\"\3\"\3\""+
		"\3\"\3#\3#\3#\3#\3#\3#\3$\3$\3$\3$\3$\3$\3%\3%\3%\3&\3&\3&\3&\3&\3&\3"+
		"&\3&\3&\3\'\3\'\3\'\3\'\3\'\3\'\3\'\3(\3(\7(\u010c\n(\f(\16(\u010f\13"+
		"(\3)\3)\3)\7)\u0114\n)\f)\16)\u0117\13)\3)\3)\3*\3*\3*\3+\3+\3+\3+\7+"+
		"\u0122\n+\f+\16+\u0125\13+\3+\5+\u0128\n+\3+\3+\3+\3+\3,\6,\u012f\n,\r"+
		",\16,\u0130\3,\3,\3-\3-\3.\3.\3/\3/\3\60\3\60\3\61\3\61\2\2\62\3\3\5\4"+
		"\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22"+
		"#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C"+
		"#E$G%I&K\'M(O)Q*S\2U+W,Y-[.]/_\60a\61\3\2\t\7\2\"\"\62;C\\aac|\4\2C\\"+
		"c|\6\2\62;C\\aac|\4\2$$^^\n\2$$))^^ddhhppttvv\4\2\f\f\17\17\5\2\13\f\17"+
		"\17\"\"\2\u0146\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3"+
		"\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2"+
		"\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3"+
		"\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2"+
		"\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\2"+
		"9\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3"+
		"\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2"+
		"\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2"+
		"a\3\2\2\2\3c\3\2\2\2\5e\3\2\2\2\7g\3\2\2\2\ti\3\2\2\2\13k\3\2\2\2\rm\3"+
		"\2\2\2\17o\3\2\2\2\21q\3\2\2\2\23s\3\2\2\2\25w\3\2\2\2\27{\3\2\2\2\31"+
		"\u0081\3\2\2\2\33\u0086\3\2\2\2\35\u008b\3\2\2\2\37\u008e\3\2\2\2!\u0091"+
		"\3\2\2\2#\u0093\3\2\2\2%\u0096\3\2\2\2\'\u0098\3\2\2\2)\u009b\3\2\2\2"+
		"+\u009f\3\2\2\2-\u00a3\3\2\2\2/\u00a7\3\2\2\2\61\u00ac\3\2\2\2\63\u00bf"+
		"\3\2\2\2\65\u00c1\3\2\2\2\67\u00c5\3\2\2\29\u00c8\3\2\2\2;\u00cd\3\2\2"+
		"\2=\u00d2\3\2\2\2?\u00d8\3\2\2\2A\u00dd\3\2\2\2C\u00e5\3\2\2\2E\u00ea"+
		"\3\2\2\2G\u00f0\3\2\2\2I\u00f6\3\2\2\2K\u00f9\3\2\2\2M\u0102\3\2\2\2O"+
		"\u0109\3\2\2\2Q\u0110\3\2\2\2S\u011a\3\2\2\2U\u011d\3\2\2\2W\u012e\3\2"+
		"\2\2Y\u0134\3\2\2\2[\u0136\3\2\2\2]\u0138\3\2\2\2_\u013a\3\2\2\2a\u013c"+
		"\3\2\2\2cd\7]\2\2d\4\3\2\2\2ef\7_\2\2f\6\3\2\2\2gh\7?\2\2h\b\3\2\2\2i"+
		"j\7-\2\2j\n\3\2\2\2kl\7/\2\2l\f\3\2\2\2mn\7,\2\2n\16\3\2\2\2op\7\61\2"+
		"\2p\20\3\2\2\2qr\7\'\2\2r\22\3\2\2\2st\7x\2\2tu\7c\2\2uv\7t\2\2v\24\3"+
		"\2\2\2wx\7k\2\2xy\7p\2\2yz\7v\2\2z\26\3\2\2\2{|\7h\2\2|}\7n\2\2}~\7q\2"+
		"\2~\177\7c\2\2\177\u0080\7v\2\2\u0080\30\3\2\2\2\u0081\u0082\7e\2\2\u0082"+
		"\u0083\7j\2\2\u0083\u0084\7c\2\2\u0084\u0085\7t\2\2\u0085\32\3\2\2\2\u0086"+
		"\u0087\7d\2\2\u0087\u0088\7q\2\2\u0088\u0089\7q\2\2\u0089\u008a\7n\2\2"+
		"\u008a\34\3\2\2\2\u008b\u008c\7?\2\2\u008c\u008d\7?\2\2\u008d\36\3\2\2"+
		"\2\u008e\u008f\7#\2\2\u008f\u0090\7?\2\2\u0090 \3\2\2\2\u0091\u0092\7"+
		"@\2\2\u0092\"\3\2\2\2\u0093\u0094\7@\2\2\u0094\u0095\7?\2\2\u0095$\3\2"+
		"\2\2\u0096\u0097\7>\2\2\u0097&\3\2\2\2\u0098\u0099\7>\2\2\u0099\u009a"+
		"\7?\2\2\u009a(\3\2\2\2\u009b\u009c\7c\2\2\u009c\u009d\7p\2\2\u009d\u009e"+
		"\7f\2\2\u009e*\3\2\2\2\u009f\u00a0\7p\2\2\u00a0\u00a1\7q\2\2\u00a1\u00a2"+
		"\7v\2\2\u00a2,\3\2\2\2\u00a3\u00a4\7q\2\2\u00a4\u00a5\7t\2\2\u00a5.\3"+
		"\2\2\2\u00a6\u00a8\4\62;\2\u00a7\u00a6\3\2\2\2\u00a8\u00a9\3\2\2\2\u00a9"+
		"\u00a7\3\2\2\2\u00a9\u00aa\3\2\2\2\u00aa\60\3\2\2\2\u00ab\u00ad\4\62;"+
		"\2\u00ac\u00ab\3\2\2\2\u00ad\u00ae\3\2\2\2\u00ae\u00ac\3\2\2\2\u00ae\u00af"+
		"\3\2\2\2\u00af\u00b0\3\2\2\2\u00b0\u00b2\7\60\2\2\u00b1\u00b3\4\62;\2"+
		"\u00b2\u00b1\3\2\2\2\u00b3\u00b4\3\2\2\2\u00b4\u00b2\3\2\2\2\u00b4\u00b5"+
		"\3\2\2\2\u00b5\62\3\2\2\2\u00b6\u00b7\7v\2\2\u00b7\u00b8\7t\2\2\u00b8"+
		"\u00b9\7w\2\2\u00b9\u00c0\7g\2\2\u00ba\u00bb\7h\2\2\u00bb\u00bc\7c\2\2"+
		"\u00bc\u00bd\7n\2\2\u00bd\u00be\7u\2\2\u00be\u00c0\7g\2\2\u00bf\u00b6"+
		"\3\2\2\2\u00bf\u00ba\3\2\2\2\u00c0\64\3\2\2\2\u00c1\u00c2\7)\2\2\u00c2"+
		"\u00c3\t\2\2\2\u00c3\u00c4\7)\2\2\u00c4\66\3\2\2\2\u00c5\u00c6\7k\2\2"+
		"\u00c6\u00c7\7h\2\2\u00c78\3\2\2\2\u00c8\u00c9\7v\2\2\u00c9\u00ca\7j\2"+
		"\2\u00ca\u00cb\7g\2\2\u00cb\u00cc\7p\2\2\u00cc:\3\2\2\2\u00cd\u00ce\7"+
		"g\2\2\u00ce\u00cf\7n\2\2\u00cf\u00d0\7u\2\2\u00d0\u00d1\7g\2\2\u00d1<"+
		"\3\2\2\2\u00d2\u00d3\7g\2\2\u00d3\u00d4\7p\2\2\u00d4\u00d5\7f\2\2\u00d5"+
		"\u00d6\7k\2\2\u00d6\u00d7\7h\2\2\u00d7>\3\2\2\2\u00d8\u00d9\7h\2\2\u00d9"+
		"\u00da\7w\2\2\u00da\u00db\7p\2\2\u00db\u00dc\7e\2\2\u00dc@\3\2\2\2\u00dd"+
		"\u00de\7g\2\2\u00de\u00df\7p\2\2\u00df\u00e0\7f\2\2\u00e0\u00e1\7h\2\2"+
		"\u00e1\u00e2\7w\2\2\u00e2\u00e3\7p\2\2\u00e3\u00e4\7e\2\2\u00e4B\3\2\2"+
		"\2\u00e5\u00e6\7t\2\2\u00e6\u00e7\7g\2\2\u00e7\u00e8\7c\2\2\u00e8\u00e9"+
		"\7f\2\2\u00e9D\3\2\2\2\u00ea\u00eb\7y\2\2\u00eb\u00ec\7t\2\2\u00ec\u00ed"+
		"\7k\2\2\u00ed\u00ee\7v\2\2\u00ee\u00ef\7g\2\2\u00efF\3\2\2\2\u00f0\u00f1"+
		"\7y\2\2\u00f1\u00f2\7j\2\2\u00f2\u00f3\7k\2\2\u00f3\u00f4\7n\2\2\u00f4"+
		"\u00f5\7g\2\2\u00f5H\3\2\2\2\u00f6\u00f7\7f\2\2\u00f7\u00f8\7q\2\2\u00f8"+
		"J\3\2\2\2\u00f9\u00fa\7g\2\2\u00fa\u00fb\7p\2\2\u00fb\u00fc\7f\2\2\u00fc"+
		"\u00fd\7y\2\2\u00fd\u00fe\7j\2\2\u00fe\u00ff\7k\2\2\u00ff\u0100\7n\2\2"+
		"\u0100\u0101\7g\2\2\u0101L\3\2\2\2\u0102\u0103\7t\2\2\u0103\u0104\7g\2"+
		"\2\u0104\u0105\7v\2\2\u0105\u0106\7w\2\2\u0106\u0107\7t\2\2\u0107\u0108"+
		"\7p\2\2\u0108N\3\2\2\2\u0109\u010d\t\3\2\2\u010a\u010c\t\4\2\2\u010b\u010a"+
		"\3\2\2\2\u010c\u010f\3\2\2\2\u010d\u010b\3\2\2\2\u010d\u010e\3\2\2\2\u010e"+
		"P\3\2\2\2\u010f\u010d\3\2\2\2\u0110\u0115\7$\2\2\u0111\u0114\5S*\2\u0112"+
		"\u0114\n\5\2\2\u0113\u0111\3\2\2\2\u0113\u0112\3\2\2\2\u0114\u0117\3\2"+
		"\2\2\u0115\u0113\3\2\2\2\u0115\u0116\3\2\2\2\u0116\u0118\3\2\2\2\u0117"+
		"\u0115\3\2\2\2\u0118\u0119\7$\2\2\u0119R\3\2\2\2\u011a\u011b\7^\2\2\u011b"+
		"\u011c\t\6\2\2\u011cT\3\2\2\2\u011d\u011e\7\61\2\2\u011e\u011f\7\61\2"+
		"\2\u011f\u0123\3\2\2\2\u0120\u0122\n\7\2\2\u0121\u0120\3\2\2\2\u0122\u0125"+
		"\3\2\2\2\u0123\u0121\3\2\2\2\u0123\u0124\3\2\2\2\u0124\u0127\3\2\2\2\u0125"+
		"\u0123\3\2\2\2\u0126\u0128\7\17\2\2\u0127\u0126\3\2\2\2\u0127\u0128\3"+
		"\2\2\2\u0128\u0129\3\2\2\2\u0129\u012a\7\f\2\2\u012a\u012b\3\2\2\2\u012b"+
		"\u012c\b+\2\2\u012cV\3\2\2\2\u012d\u012f\t\b\2\2\u012e\u012d\3\2\2\2\u012f"+
		"\u0130\3\2\2\2\u0130\u012e\3\2\2\2\u0130\u0131\3\2\2\2\u0131\u0132\3\2"+
		"\2\2\u0132\u0133\b,\2\2\u0133X\3\2\2\2\u0134\u0135\7*\2\2\u0135Z\3\2\2"+
		"\2\u0136\u0137\7+\2\2\u0137\\\3\2\2\2\u0138\u0139\7=\2\2\u0139^\3\2\2"+
		"\2\u013a\u013b\7<\2\2\u013b`\3\2\2\2\u013c\u013d\7.\2\2\u013db\3\2\2\2"+
		"\r\2\u00a9\u00ae\u00b4\u00bf\u010d\u0113\u0115\u0123\u0127\u0130\3\b\2"+
		"\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}