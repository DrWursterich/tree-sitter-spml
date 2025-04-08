import XCTest
import SwiftTreeSitter
import TreeSitterSpml

final class TreeSitterSpmlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_spml())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading spml grammar")
    }
}
